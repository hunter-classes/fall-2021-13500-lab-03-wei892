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
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); //exit if failed to open the file
    }

  std::string junk;
  getline(fin, junk); //read one line from the file

  //declaring the variables
  std::string data_date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  //double to store east basin storage
  double east_storage; 
  //loop to read all the data
  while (fin >> data_date >> eastSt >> eastEl >> westSt >> westEl)
    {
      //this string reads the file line by line, 5 values are expected

      fin.ignore(INT_MAX, '\n'); //skips to the next line, ignores rest of the colomns
      if (date == data_date)
	{
	  
	  return eastSt;
	}
    }
  fin.close();
  return east_storage;
}


double get_min_east()
{
  //variable to store min value
  double min = INT_MAX;
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail())
    {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); //exit if failed to open the file
    }
  std::string junk;
  getline(fin, junk); //read one line from the file

  std::string data_date;
  double eastSt;
  //only two variable are created bcuz only two columns are required;
  
  while (fin >> data_date >> eastSt)
    {
      //only two values are read bcuz only the two values are needed for this part
      fin.ignore(INT_MAX, '\n'); //skips to the next line, ignores rest of the colomns
      if (eastSt < min)
	{
	  min = eastSt;
	}
    }
  fin.close();
  return min;
}


double get_max_east()
{
  //variable to store max value
  double max = INT_MIN;
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail())
    {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); //exit if failed to open the file
    }
  std::string junk;
  getline(fin, junk); //read one line from the file


  std::string data_date;
  double eastSt;
  //i only created these two bcuz only these two coloumns were necessary for part c
  
  while (fin >> data_date >> eastSt)
    {
      //only two values are read bcuz only the two values are needed for this part
      fin.ignore(INT_MAX, '\n'); //skips to the next line, ignores rest of the colomns
      if (eastSt> max)
	{
	  max = eastSt;
	}
    }
  fin.close();
  return max;
}
