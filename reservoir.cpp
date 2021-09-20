// this file will contain the prototype to get the east storage

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date)
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail())
    {
      std::cerr << "File cannot be opened for reading." << endl;
      exit(1); //exit if failed to open the file
    }

  std::string junk;
  getline(fin, junk); //read one line from the file

  //declaring the variables
  std::string data_date;
  std::string eastSt;
  std::string eastEl;
  std::string westSt;
  std::string westEl;

  //double to store east basin storage
  double east_storage; 
  //loop to read all the data
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
      //this string reads the file line by line, 5 values are expected

      fin.ignore(INT_MAX, '\n'); //skips to the next line, ignores rest of the colomns
      if (date == data_date)
	{
	  east_storage = std::stod(eastSt);
	  return east_storage;
	}
    }
  fin.close();
}


