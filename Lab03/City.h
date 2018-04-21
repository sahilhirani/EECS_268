/**
*	@file City.h
*	@author Sahil Hirani
*	@date 02/17/2017
*	@brief A header file for City class
*/

#ifndef CITY_H
#define CITY_H
#include <string>
#include <iostream>

class City
{
public:
  /** @pre None.
	*   @post Intitializes variables
	*   @return None
	*/
  City();
  /** @pre None.
	*   @post Sets city name
	*   @return none
	*/
  void setName(std::string name);
  /** @pre None.
	*   @post sets population
	*   @return none
	*/
  void setPop(int pop);
  /** @pre None.
	*   @post sets infection level
	*   @return none
	*/
  void setInfectlvl(int lvl);
  /** @pre None.
	*   @post None.
	*   @return returns City Name
	*/
  std::string getName();
  /** @pre None.
	*   @post None.
	*   @return returns population
	*/
  int getPop();
  /** @pre None.
	*   @post None.
	*   @return returns infection level
	*/
  int getInfectlvl();

private:
  std::string m_cityname;
  int m_population;
  int m_infectlvl;

};

#endif
