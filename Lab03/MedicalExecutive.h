/**
*	@file MedicalExecutive.h
*	@author Sahil Hirani
*	@date 02/17/2017
*	@brief A header file for the MedicalExecutive class
*/

#ifndef MEDICAL_EXECUTIVE_H
#define MEDICAL_EXECUTIVE_H
#include "LinkedList.h"
#include "Node.h"
#include "City.h"
#include <string>
#include <iostream>
#include <fstream>

class MedicalExecutive
{
public:
  /** @pre None.
	*   @post Reads file and throws cities into sort method
	*   @return None.
	*/
  MedicalExecutive(std::string filename);
  /** @pre None.
	*   @post Creates LinkedList
	*   @return Noce
	*/
  void sort(LinkedList<City>& myList, City& myCity);
  /** @pre None.
	*   @post Runs Interactive menu with User
	*   @return none
	*/
  void run();
  /** @pre None.
	*   @post increases infection level of all cities
	*   @return none
	*/
  void increaseInfectLvl();
  /** @pre None.
	*   @post increases infection level of a specific city
	*   @return none
	*/
  void increaseInfectLvlspecific(City tempCity);

private:
  std::string m_filename;
  bool isopen;
  LinkedList<City> infectedCityList;
  LinkedList<City> quarintinedCityList;
  LinkedList<City> newCityList;
};

#endif
