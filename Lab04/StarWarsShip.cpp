/**
*	@file StarWarsShip.cpp
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Class defintion file
*/

#include "StarWarsShip.h"

StarWarsShip::StarWarsShip(std::string uni, std::string pilotName, int attpow, int hull, int shield, std::string lastWords)
{
  m_universe = uni;
  m_pilotName = pilotName;
  m_attackPower = attpow;
  m_currentHull = hull;
  m_maxHull = hull;
  m_shields = shield;
  m_lastWords = lastWords;

}

StarWarsShip::~StarWarsShip()
{
  std::cout << "The final message from " << m_pilotName << ": " << m_lastWords << "\n";
}

int StarWarsShip::attackPower() const
{
  return(m_attackPower);
}

int StarWarsShip::currentHull() const
{
  return(m_currentHull);
}

int StarWarsShip::maxHull() const
{
  return(m_maxHull);
}

bool StarWarsShip::takeDamage(int amount)
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

bool StarWarsShip::shields() const
{
  return(m_shields);
}

std::string StarWarsShip::universe() const
{
  return(m_universe);
}

std::string StarWarsShip::status() const
{
  //return("Test string");
  //m_status = "hi";//m_pilotName + "\'s ship has " + std::to_string(m_currentHull) + " out of " + std::to_string(m_maxHull) + ".";
  return(m_pilotName + "\'s ship/ has " + std::to_string(m_currentHull) + " out of " + std::to_string(m_maxHull) + ".");
}

std::string StarWarsShip::getPilot() const
{
  return(m_pilotName);
}

std::string StarWarsShip::getLastWords() const
{
  return(m_lastWords);
}

void StarWarsShip::setAttack(int power)
{
  m_attackPower = power;
}

void StarWarsShip::setHull(int hull)
{
  m_currentHull = hull;
}

void StarWarsShip::setShield(int shield)
{
  m_shields = shield;
}

void StarWarsShip::setPilot(std::string pilot)
{
  m_pilotName = pilot;
}

void StarWarsShip::setUniverse(std::string uni)
{
  m_universe = uni;
}

void StarWarsShip::setLastWords(std::string words)
{
  m_lastWords = words;
}
