/**
*	@file main.cpp
*	@author Sahil Hirani
*	@date 02/17/2017
*	@brief Main file, controls command line arguments and send it into medical executive
*/

#include <iostream>
#include "MedicalExecutive.h" // This is where the program runs

int main(int argc, char* argv[])
{
  if(argc < 2) //Checks to see if a file name was given
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     MedicalExecutive exec(argv[1]); //creation of executive object
     exec.run(); //handles the calling of all other member methods
  }

  return(0);
}
