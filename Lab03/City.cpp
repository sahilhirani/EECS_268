/**
*	@file City.cpp
*	@author Sahil Hirani
*	@date 02/17/2017
*	@brief A class definition file for City class
*/

#include "City.h"

City::City()
{
  m_infectlvl = 0;
  m_cityname = " ";
  m_population = 0;
}

void City::setName(std::string name)
{
  m_cityname = name;
}

void City::setPop(int pop)
{
  m_population = pop;
}

void City::setInfectlvl(int lvl)
{
  m_infectlvl = lvl;
}

std::string City::getName()
{
  return(m_cityname);
}

int City::getPop()
{
  return(m_population);
}

int City::getInfectlvl()
{
  return(m_infectlvl);
}
