/**
*	@file main.cpp
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Main file, controls command line arguments and send it into flight manager
*/

#include <iostream>
#include "FlightManager.h" // This is where the program runs
#include "SpaceShip.h"

int main(int argc, char* argv[])
{
  if(argc < 2) //Checks to see if a file name was given
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     FlightManager flight(argv[1]); //creation of flight manager object
     flight.run(); //handles the whole program
  }

  return(0);
}
