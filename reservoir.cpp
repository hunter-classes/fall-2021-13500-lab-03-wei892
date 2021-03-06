/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab3

This file includes 4 prototypes
get east storage will return the east side storage based on the date given
min east storage will return the smallest storage value in the data on the east side
max east storage will return the largest storage value in the data on the east side
compare basin will return the side that has a greater elevation
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"


//prototype to get east storage
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
  return eastSt;
}


//---------------------------------------------------------------

//prototype to get min east storage
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


//---------------------------------------------------

//prototype to get the max east storage
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


//-----------------------------------------------


//prototype to comepare basins
std::string compare_basins(std::string date)
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
  
  //loop to read all the data
  while (fin >> data_date >> eastSt >> eastEl >> westSt >> westEl)
    {
      //this string reads the file line by line, 5 values are expected

      fin.ignore(INT_MAX, '\n'); //skips to the next line, ignores rest of the colomns
      if (date == data_date)
	{
	  if (westEl > eastEl)
	    {
	      return "West";
	    }
	  else if ( westEl < eastEl)
	    {
	      return "East";
	    }
	  else
	    {
	      return "Equal";
	    }
	}
    }
  fin.close();
  return "Invalid";
}
