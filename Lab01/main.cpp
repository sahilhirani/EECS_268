/*
File Name: Pokemon
Author: Sahil Hirani
KUID: 2831316
Email Address: s679h568@ku.edu
Lab Assignment Number: 1
Description: This program is created to be used as Pokedex, it can search and
print out the Pokemon's American or Japanese name and can also create files
with the Pokemon's Japanese names.
Last Changed: 02/01/2017
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
     Executive exec(argv[1]); //creation of executive object
     exec.run(); //handles the calling of all other member methods
  }

  return(0);
}
