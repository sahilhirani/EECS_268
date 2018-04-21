#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <fstream>
#include <string>
#include "Pokemon.h"

class Executive
{
public:
  Executive(std::string filename); //Constructor
  ~Executive(); //Destructor
  void run(); //runs everything
  void filetoPoke(std::string filename); //input file info into

private:
  int m_size;
  Pokemon* poke1 = nullptr;
  bool m_isopen;//if filename is readable it is true

};

#endif
