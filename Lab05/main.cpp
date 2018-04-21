/**
*	@file main.cpp
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief main file for Lab 5
*/

#include <iostream>
#include "Theater.h" // This is where the program runs

int main(int argc, char* argv[])
{
  if(argc < 2) //Checks to see if a file name was given
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Theater th1; //creation of Theater object
     th1.run(argv[1]); //handles the whole program
  }

  return(0);
}
