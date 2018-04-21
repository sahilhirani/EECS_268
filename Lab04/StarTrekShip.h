/**
*	@file StarTrekShip.h
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Class header file
*/

#ifndef STAR_TREK_SHIP_H
#define STAR_TREK_SHIP_H
#include <string>
#include <iostream>
#include "SpaceShip.h"

class StarTrekShip: public SpaceShip
{

public:
  StarTrekShip(std::string uni, std::string capName, int attpow, int numCrew, int hull, int shield);//sets all member variables
  ~StarTrekShip();//prints message after ship dies
  int attackPower() const; //Returns attack power of ship
  int currentHull() const; //Returns the amount of damage the hull can still sustain. Once a hull value reaches 0, the ship is destroyed
  int maxHull() const; //Return the value the hull started the fight with
  bool takeDamage(int amount); //Reduces the hull the amount given. If shields are on, the damage is halved. If the ship dies, return true, otherwise return false
  bool shields() const; //returns the status of the shields. True indicates shields are on, false indicates shields are off or disabled. When shields are on, the ship takes 50% damage (rounded down)
  std::string universe() const; //returns the Universe the ship is from, StarTrek or StarWars
  std::string status() const; //returns a message indicating the current status of the ship
  std::string getCap() const; //returns captain name
  int getCrew() const; //returns crew number
  void setAttack(int power); // sets member variable
  void setHull(int hull);// sets member variable
  void setShield(int shield);// sets member variable
  void setCrew(int crew); // sets member variable
  void setUniverse(std::string uni); // sets member variable
  void setCap(std::string capName); // sets member variable


private:
  int m_maxHull;
  int m_currentHull;
  bool m_shields;
  std::string m_universe;
  std::string m_capName;
  int m_attackPower;
  int m_numCrew;
  std::string m_status;
};

#endif
