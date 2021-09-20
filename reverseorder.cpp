/*

 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2)
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail())
    {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
    }

  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  //declaring variables
  std::string day;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  std::string date_order[365];
  double west_elev[365];
  int numdays = 0;
  
  while(fin >> day >> eastSt >> eastEl >> westSt >> westEl)
    {
      // this loop reads the file line-by-line
      // extracting 5 values on each iteration

      fin.ignore(INT_MAX, '\n'); //skips to the end of line,
      //ignoring the remaining column
      if (date1 <= day && day <= date2)
	{
	  date_order[numdays] = day;
	  west_elev[numdays] = westEl;
	  numdays++;
	}
    }
  
  fin.close();
  numdays--;
  
  for (int i = numdays; i>=0; i--)
    {
      std::cout << date_order[i];
      std::cout << "\t" << west_elev[i] << " ft" << std::endl;
    }
}
