/**
*	@file main.cpp
*	@author Sahil Hirani
*	@date 02/09/2017
*	@brief Main file that runs the program
*/
#include <iostream>
#include <string>
#include "Executive.h"
#include "LinkedListTester.h"

int main(int argc, char* argv[])
{

  std::string interactive = "-i";
  std::string test = "-t";

  if(argc < 2) //Checks to see if a file name was given
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else if(argv[1] == interactive)
  {
     Executive exec; //creation of executive object
     exec.run(); //handles the calling of all other member methods
     return(0);
  }
  else if(argv[1] == test)
  {
    LinkedListTester tests; //creation of LinkedListTester Object
    tests.runTests(); //RUNS THE TEST!
    return(0);
  }
  return(0);
}
