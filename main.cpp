/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab3

This file is the main file where it includes all the 
tests by calling the prototypes
*/ 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  //tests for getting east basin storage
  //test one
  std::cout << "Enter date: 05/20/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons" << std::endl;
  //test two
  std::cout << "Enter date: 03/12/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("03/12/2018") << " billion gallons" << std::endl;
  //test three
  std::cout << "Enter date: 04/21/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("04/21/2018") << " billion gallons" << std::endl;



  
  //test for min and max
  std::cout << "\nMinimun storage in East Basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "Maximum storage in East Basin: " << get_max_east() << " billion gallons" << std::endl;

  
  
  //test for comparing west and east
  //test one
  std::cout << "\nDate entered: 09/13/2018" << std::endl;
  std::cout << compare_basins("09/13/2018") << " basin had higher elevation" << std::endl;
  //test two
  std::cout << "\nDate entered: 09/17/2018" << std::endl;
  std::cout << compare_basins("09/17/2018") << " basin had higher elevation" << std::endl;
  //test three
  std::cout << "\nDate entered: 08/20/2018" << std::endl;
  std::cout << compare_basins("08/20/2018") << " basin had higher elevation" << std::endl;


  
  //test for reserve order
  std::cout << "\nEarlier date: 05/29/2018\nLater date: 06/02/2018" << std::endl;
  std::cout << "\n";
  reverse_order("05/29/2018", "06/02/2018"); 

  std::cout << "\nEarlier date: 07/29/2018\nLater date: 08/04/2018" << std::endl;
  std::cout << "\n";
  reverse_order("07/29/2018", "08/04/2018");

  std::cout << "\nEarlier date: 02/03/2018\nLater date: 02/08/2018" << std::endl;
  std::cout << "\n";
  reverse_order("02/03/2018", "02/08/2018"); 

  return 0;
}
