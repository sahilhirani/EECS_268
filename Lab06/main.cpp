/**
*	@file main.cpp
*	@author Sahil Hirani
*	@date 03/17/2017
*	@brief main file for Lab 6
*/

#include <iostream>
#include "Executive.h" // This is where the program runs

int main(int argc, char* argv[])
{
  if(argc < 2) //Checks to see if a file name was given
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Executive exec; //creation of executive object
     exec.run(argv[1]); //handles the whole program
  }

  return(0);
}
