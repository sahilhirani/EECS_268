/**
*	@file SpaceShip.h
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Interface header file
*/

#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H
#include <string>


class SpaceShip
{
public:

  virtual int attackPower() const = 0;
  virtual int currentHull() const = 0;
  virtual int maxHull() const = 0;
  virtual bool takeDamage(int amount) = 0;
  virtual bool shields() const = 0;
  virtual std::string universe() const = 0;
  virtual std::string status() const = 0;
  virtual ~SpaceShip(){};

protected:


};

#endif
