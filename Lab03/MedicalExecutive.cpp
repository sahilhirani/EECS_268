/**
*	@file MedicalExecutive.cpp
*	@author Sahil Hirani
*	@date 02/17/2017
*	@brief A class definition file for the MedicalExecutive class
*/
#include "MedicalExecutive.h"
#include "City.h"
#include "Node.h"
#include <fstream>
#include <iostream>
#include <limits>


MedicalExecutive::MedicalExecutive(std::string filename)
{
  std::string cityname;
  std::string pop;
  std::string infectlvl;
  int inlvl;
  City tempcity;
  m_filename = filename;
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open() == true)
  {
    while(!inFile.eof())
    {
      std::getline(inFile, cityname, ','); //inputs data stops at ','
      std::getline(inFile, pop, ',');
      std::getline(inFile, infectlvl);
      tempcity.setName(cityname);
      tempcity.setPop(std::stoi(pop));
      inlvl = std::stoi(infectlvl);
      tempcity.setInfectlvl(std::stoi(infectlvl));
      if(inFile.eof() == true)
      {
        break;
      }
      if(inlvl == 4)
      {
        sort(quarintinedCityList, tempcity);
      }
      else
      {
        sort(infectedCityList, tempcity);
      }
    }
    isopen = true;
  }
  else
  {
    isopen = false;
  }
  inFile.close();
}

void MedicalExecutive::run()
{
  if(isopen == true)
  {

    int choice = 0;
    while(choice != 6)
    {
      std::cout << "Welcome to Outbreak!\n";
      std::cout << "Make a selection:\n";
      std::cout << "1) Increase infection level of all cities\n";
      std::cout << "2) Increase infection level of specific city\n";
      std::cout << "3) Print status of specific city\n";
      std::cout << "4) Create quarantine log\n";
      std::cout << "5) Print all cities above an infection level\n";
      std::cout << "6) Exit\n";
      std::cout << "Choice: ";
      std::cin >> choice;
      while ( std::cin.fail() )
      {
        std::cin.clear(); // unset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> choice;
      }
      if((choice <= 0) || (choice > 6))
      {
        std::cout <<"The chioce you entered is not valid please try again!\n";
      }
      else if(choice == 1)
      {
        std::cout << "Increasing Infection Level Of All Cities!\n";
        increaseInfectLvl();

      }
      else if(choice == 2)
      {
        std::string userCity;
        std::cin.ignore(1, '\n');
        std::cout << "Which City do you want to Infect?: ";
        std::getline(std::cin, userCity);
        int pos = 0;
        for(int i = 1; i <= infectedCityList.getLength(); i++)
        {
          City temp = infectedCityList.getEntry(i);
          if(temp.getName() == userCity)
          {
            pos = i;
            break;
          }
        }
        if(pos == 0)
        {
          std::cout << "Sorry, \"" << userCity << "\" is not a city in the list.\n";
        }
        else
        {
          City temp = infectedCityList.getEntry(pos);
          infectedCityList.removeAt(pos);
          increaseInfectLvlspecific(temp);
        }
      }
      else if(choice == 3)
      {
        std::string userCity2;
        std::cin.ignore(1, '\n');
        std::cout << "Which City do you want to see the status of?: ";
        std::getline(std::cin, userCity2);
        int pos = 0;
        for(int i = 1; i <= infectedCityList.getLength(); i++)
        {
          City temp2 = infectedCityList.getEntry(i);
          if(temp2.getName() == userCity2)
          {
            pos = i;
            break;
          }
        }
        if(pos == 0)
        {
          std::cout << "Sorry, \"" << userCity2 << "\" is not a city in the list.\n";
        }
        else
        {
          City temp = infectedCityList.getEntry(pos);
          std::cout << "City Name: " << temp.getName() << "\n";
          std::cout << "Population: " << temp.getPop() << "\n";
          std::cout << "Infection Level: " << temp.getInfectlvl() << "\n";
        }
      }
      else if(choice == 4)
      {
        std::string filename;
        std::ofstream outFile;
        std::cout << "Please enter a filename with .txt at the end: ";
        std::cin >> filename;
        outFile.open(filename);
        for(int i = 1; i <= quarintinedCityList.getLength(); i++)
        {
          City temp = quarintinedCityList.getEntry(i);
          outFile << temp.getName() << ", " << temp.getPop() << ", " << temp.getInfectlvl() << "\n";
        }
        outFile.close();
        std::cout << "Your File has been created!\n";
      }
      else if(choice == 5)
      {
        int userInfLvl;
        std::cout<<"Enter an infection level: ";
        std::cin>>userInfLvl;
        while(userInfLvl >= 4)
        {
          std::cout<<"Please choice an infection level that is lower than 4: ";
          std::cin>>userInfLvl;
        }
        for(int i = 1; i <= infectedCityList.getLength(); i++)
        {
          City temp = infectedCityList.getEntry(i);
          if(temp.getInfectlvl()>= userInfLvl)
          {
            std::cout<<temp.getName()<<"\n";
          }
        }
        for(int i = 1; i <= quarintinedCityList.getLength(); i++)
        {
          City temp = quarintinedCityList.getEntry(i);
          if(temp.getInfectlvl()>= userInfLvl)
          {
            std::cout<<temp.getName()<<"\n";
          }
        }
      }
      else if(choice == 6)
      {
        std::cout << "Program is exitting!\n GoodBye!\n";
      }
    }
  }
  else
  {
    std::cout << "FILENAME NOT VALID PLEASE INPUT CORRECT FILENAME WITH .TXT !!!!!!!\n";
  }
}

void MedicalExecutive::sort(LinkedList<City>& myList, City& myCity)
{
  if(myList.getLength() == 0)
  {
    myList.addFront(myCity);
  }
  else
  {
    City tempCity;
    for(int i = 1; i <= myList.getLength(); i++)
    {
      tempCity = myList.getEntry(i);
      if(myCity.getPop() > tempCity.getPop())
      {
        myList.insert(i, myCity);
        break;
      }
      else if(myCity.getPop() == tempCity.getPop())
      {
        if(myCity.getInfectlvl() > tempCity.getInfectlvl())
        {
          myList.insert(i, myCity);
          break;
        }
        else if(myCity.getInfectlvl() == tempCity.getInfectlvl())
        {
          if(myCity.getName().compare( tempCity.getName() ) <= 0)
          {
            myList.insert(i, myCity);
            break;
          }
        }
      }
      else
      {
        myList.addBack(myCity);
        break;
      }
    }
  }
}

void MedicalExecutive::increaseInfectLvl()
{
  City tempCity;
  int pos = infectedCityList.getLength();
  for(int i = pos; i >= 1; i--)
  {
    tempCity = infectedCityList.getEntry(i);
    infectedCityList.removeAt(i);
    int pop = tempCity.getPop();
    int inflvl = tempCity.getInfectlvl();
    tempCity.setInfectlvl((inflvl +1));
    if(tempCity.getInfectlvl() == 0)
    {
      sort(infectedCityList, tempCity);
    }
    else if(tempCity.getInfectlvl() == 1)
    {
      tempCity.setPop(pop*.9);
      sort(infectedCityList, tempCity);
    }
    else if(tempCity.getInfectlvl() == 2)
    {
      tempCity.setPop(pop*.8);
      sort(infectedCityList, tempCity);
    }
    else if(tempCity.getInfectlvl() == 3)
    {
      City newCity;
      std::string newName = "New " + tempCity.getName();
      newCity.setName(newName);
      newCity.setPop(pop * 0.25);
      tempCity.setPop(pop * 0.75);
      newCity.setInfectlvl(0);
      sort(infectedCityList, tempCity);
      sort(newCityList, newCity);
    }
    else if(tempCity.getInfectlvl() == 4)
    {
      sort(quarintinedCityList, tempCity);
      std::cout << tempCity.getName() << " has been placed in quaratine!\n";
    }
  }
  if(newCityList.getLength() > 0)
  {
    City newtemp;
    for(int i = 1; i <= newCityList.getLength(); i++)
    {
      newtemp = newCityList.getEntry(i);
      sort(infectedCityList, newtemp);
    }
    for(int j = 1; j <= newCityList.getLength(); j++)
    {
      newCityList.removeAt(j);
    }
  }
}
void MedicalExecutive::increaseInfectLvlspecific(City tempCity)
{
  int pop = tempCity.getPop();
  int inflvl = tempCity.getInfectlvl();
  tempCity.setInfectlvl(inflvl +1);
  if(tempCity.getInfectlvl() == 0)
  {
    sort(infectedCityList, tempCity);
  }
  else if(tempCity.getInfectlvl() == 1)
  {
    tempCity.setPop(pop*.9);
    sort(infectedCityList, tempCity);
  }
  else if(tempCity.getInfectlvl() == 2)
  {
    tempCity.setPop(pop*.8);
    sort(infectedCityList, tempCity);
  }
  else if(tempCity.getInfectlvl() == 3)
  {
    City newCity;
    std::string newName = "New " + tempCity.getName();
    newCity.setName(newName);
    newCity.setPop(pop * 0.25);
    tempCity.setPop(pop * 0.75);
    newCity.setInfectlvl(0);
    sort(infectedCityList, tempCity);
    sort(infectedCityList, newCity);
  }
  else if(tempCity.getInfectlvl() == 4)
  {
    sort(quarintinedCityList, tempCity);
    std::cout << tempCity.getName() << " has been placed in quaratine!\n";
  }
}
