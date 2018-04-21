/**
*	@file FlightManager.h
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Class header file
*/

#ifndef FLIGHT_MANAGER
#define FLIGHT_MANAGER
#include <fstream>
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "SpaceShip.h"
#include "StarWarsShip.h"
#include "StarTrekShip.h"

class FlightManager
{

public:
  FlightManager(std::string filename);
  ~FlightManager();
  void run();


private:
  LinkedList<SpaceShip*>* m_fight = new LinkedList<SpaceShip*>();
  StarWarsShip* myShip = nullptr;
  StarTrekShip* myShip2 = nullptr;
  bool isopen;

};
#endif
