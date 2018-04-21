/**
*	@file StarTrekShip.cpp
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Class definition file
*/

#include "StarTrekShip.h"

StarTrekShip::StarTrekShip(std::string uni, std::string capName, int attpow, int numCrew, int hull, int shield)
{
  m_universe = uni;
  m_capName = capName;
  m_attackPower = attpow;
  m_numCrew = numCrew;
  m_currentHull = hull;
  m_maxHull = hull;
  m_shields = shield;

}

StarTrekShip::~StarTrekShip()
{
  std::cout <<"The final message from " << m_capName <<": My greatest honor was being the captain for "<< m_numCrew <<" crew members.\n";
}

int StarTrekShip::attackPower() const
{
  return(m_attackPower);
}

int StarTrekShip::currentHull() const
{
  return(m_currentHull);
}

int StarTrekShip::maxHull() const
{
  return(m_maxHull);
}

bool StarTrekShip::takeDamage(int amount)
{
  if(m_shields == 1)
  {
    amount = amount/2;
    m_currentHull = m_currentHull - amount;
    if(m_currentHull <= 0)
    {
      return(true);
    }
    else
    {
      return(false);
    }
  }
  else
  {
    m_currentHull = m_currentHull - amount;
    if(m_currentHull <= 0)
    {
      return(true);
    }
    else
    {
      return(false);
    }
  }
}

bool StarTrekShip::shields() const
{
  return(m_shields);
}

std::string StarTrekShip::universe() const
{
  return(m_universe);
}

std::string StarTrekShip::status() const
{
  //m_status = "hi";//m_capName + "\'s ship holding " + std::to_string(m_numCrew) + " crew members has " + std::to_string(m_currentHull) + " out of " + std::to_string(m_maxHull) + " remaining.";
  return(m_capName + "\'s ship holding " + std::to_string(m_numCrew) + " crew members has " + std::to_string(m_currentHull) + " out of " + std::to_string(m_maxHull) + " remaining.");
}

std::string StarTrekShip::getCap() const
{
  return(m_capName);
}

int StarTrekShip::getCrew() const
{
  return(m_numCrew);
}

void StarTrekShip::setAttack(int power)
{
  m_attackPower = power;
}

void StarTrekShip::setHull(int hull)
{
  m_currentHull = hull;
}

void StarTrekShip::setShield(int shield)
{
  m_shields = shield;
}

void StarTrekShip::setCrew(int crew)
{
  m_numCrew = crew;
}
void StarTrekShip::setUniverse(std::string uni)
{
  m_universe = uni;
}
void StarTrekShip::setCap(std::string capName)
{
  m_capName = capName;
}
