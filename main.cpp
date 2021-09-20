// add your code as appropriate 
#include <iostream>
#include "reservoir.h"

int main()
{
  //tests for getting east basin storage
  //test one
  std::cout << "Enter date: 05/20/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons" << std::endl;
  //test two
  std::cout << "Enter date: 03/12/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("03/12/2018") << " billion gallons" << std::endl;

  

  

  
  return 0;
}
