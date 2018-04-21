/**
*	@file FlightManager.cpp
*	@author Sahil Hirani
*	@date 02/26/2017
*	@brief Class Definition file
*/

#include "FlightManager.h"
#include "SpaceShip.h"
#include "StarTrekShip.h"
#include "StarWarsShip.h"
#include <string>

FlightManager::FlightManager(std::string filename)
{
  std::string universe;//Universe
  std::string input1;//Captain or Pilot name
  std::string input2;// Attack Power
  std::string input3;// Number of Crew or Max hull
  std::string input4;// max hull value or shield status
  std::string input5;// shield status or last words
  int attackPow;
  int hull;
  int numCrew;
  int shield;
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open() == true)
  {
    isopen = true;
    while(!inFile.eof())
    {
      std::getline(inFile, universe, ','); //inputs data stops at ','
      std::getline(inFile, input1, ',');
      std::getline(inFile, input2, ',');
      std::getline(inFile, input3, ',');
      std::getline(inFile, input4, ',');
      std::getline(inFile, input5);
      if(inFile.eof() == true)
      {
        break;
      }
      if(universe == "StarWars")
      {
        attackPow = std::stoi(input2);
        hull = std::stoi(input3);
        shield = std::stoi(input4);
        myShip = new StarWarsShip(universe, input1, attackPow, hull, shield, input5);
        m_fight -> addBack(myShip);

      }
      else if(universe == "StarTrek")
      {
        attackPow = std::stoi(input2);
        numCrew = std::stoi(input3);
        hull = std::stoi(input4);
        shield = std::stoi(input5);
        myShip2 = new StarTrekShip(universe, input1, attackPow, numCrew, hull, shield);
        m_fight -> addBack(myShip2);
      }
    }
  }
  else
  {
    isopen = false;
  }
  inFile.close();
}

void FlightManager::run()
{
  if(isopen == false)
  {
    std::cout <<"FILENAME IS NOT VALID!\n";
  }
  else
  {
    int dmg = 0;
	int round = 1;
	bool foundship = false;

	std::cout<< "It all started with...\n";
	std::cout<< "\n";
	while (m_fight -> getLength() != 1)// continues loops until there is only 1 object left in list
	{
		std::cout<<"\nRound: "<<round<< "\n";
		round++;
		for (int i=1; i <= m_fight -> getLength(); i++)//creates a for loop to look through entire list
		{
			if (m_fight -> getEntry(i)->universe() == "StarWars")//looks for first 'i' that is StarWars
			{
				for (int j = 1; j <= m_fight ->getLength(); j++)
				{

					if (m_fight -> getEntry(j)->universe() == "StarTrek")
					{
						dmg = m_fight -> getEntry(i)->attackPower();//sets damage
						bool tempDestroyed = m_fight -> getEntry(j)->takeDamage(dmg); //deals damage to star trek
						foundship = true;
						if (tempDestroyed)
						{
              SpaceShip* del = m_fight -> getEntry(j);
              delete del;
							m_fight -> removeAt(j);
						}
					}
					break;
				}
				if (foundship == false)
				{
					for (int j = 1; j <= m_fight -> getLength(); j++)//if no ships are found of oppisote type it will attack its own kind
					{
						if (j != i)
						{
							dmg = m_fight -> getEntry(i)->attackPower();
							bool tempDestroyed = m_fight -> getEntry(j)->takeDamage(dmg);
							if (tempDestroyed)
							{
                SpaceShip* del = m_fight -> getEntry(j);
                delete del;
								m_fight -> removeAt(j);
							}
							break;
						}
					}
				}
				foundship = false;
			}
			else if (m_fight -> getEntry(i)->universe() == "StarTrek")
			{
				for (int j = 1; j <= m_fight -> getLength(); j++)
				{
					if (m_fight -> getEntry(j)->universe() == "StarWars")
					{
						dmg = m_fight -> getEntry(i)->attackPower();//sets damage
						bool tempDestroyed = m_fight -> getEntry(j)->takeDamage(dmg); //deals damage to star wars
						foundship = true;
						if (tempDestroyed)
						{
              SpaceShip* del = m_fight -> getEntry(j);
              delete del;
							m_fight -> removeAt(j);
						}
						break;
					}
				}
				if (foundship == false)
				{
					for (int j = 1; j <= m_fight -> getLength(); j++)
					{
						if (j != i)
						{
							dmg = m_fight -> getEntry(i)->attackPower();
							bool tempDestroyed = m_fight -> getEntry(j)->takeDamage(dmg);
							if (tempDestroyed)
							{
                SpaceShip* del = m_fight -> getEntry(j);
                delete del;
								m_fight -> removeAt(j);
							}
							break;
						}
					}
				}
				foundship = false;
			}
		}
		for(int i = 1; i<=m_fight -> getLength();i++)//displays status after end of round
		{
			std::cout<< m_fight -> getEntry(i)->status() << "\n";
		}
		if (m_fight -> getLength() == 1)//displays winner
		{
				std::cout<< std::endl << m_fight -> getEntry(1)->universe()<< " WINS!\n";
		}
	 }
  }
}

FlightManager::~FlightManager()
{
  std::cout << "The Winners Destroyed method, good thing he/she never was destroyed!\n";
  for(int i = m_fight -> getLength(); i > 0 ; i--)
  {
    SpaceShip* del = m_fight -> getEntry(i);
    delete del;
  }
  delete m_fight;
}
