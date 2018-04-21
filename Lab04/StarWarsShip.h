/**
*	@file StarWarsShip.h
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Class header file
*/

#ifndef STAR_WARS_SHIP_H
#define STAR_WARS_SHIP_H
#include <string>
#include <iostream>
#include "SpaceShip.h"

class StarWarsShip: public SpaceShip
{

public:
  StarWarsShip(std::string uni, std::string pilotName, int attpow, int hull, int shield, std::string lastWords);//sets all member variables
  ~StarWarsShip();//prints message after ship dies
  int attackPower() const; //Returns attack power of ship
  int currentHull() const; //Returns the amount of damage the hull can still sustain. Once a hull value reaches 0, the ship is destroyed
  int maxHull() const; //Return the value the hull started the fight with
  bool takeDamage(int amount); //Reduces the hull the amount given. If shields are on, the damage is halved. If the ship dies, return true, otherwise return false
  bool shields() const; //returns the status of the shields. True indicates shields are on, false indicates shields are off or disabled. When shields are on, the ship takes 50% damage (rounded down)
  std::string universe() const; //returns the Universe the ship is from, StarTrek or StarWars
  std::string status() const; //returns a message indicating the current status of the ship
  std::string getPilot() const; //returns pilot name
  std::string getLastWords() const; // returns last words of pilot
  void setAttack(int power);
  void setHull(int hull);
  void setShield(int shield);
  void setPilot(std::string pilot);
  void setUniverse(std::string uni);
  void setLastWords(std::string words);

private:
  int m_maxHull;
  int m_currentHull;
  bool m_shields;
  std::string m_universe;
  std::string m_pilotName;
  int m_attackPower;
  std::string m_lastWords;
  std::string m_status;

};

#endif
