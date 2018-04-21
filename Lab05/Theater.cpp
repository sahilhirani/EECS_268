/**
*	@file Theater.cpp
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief Theater class defenition file
*/

#include "Theater.h"
#include <iostream>
#include <fstream>

Theater::Theater()
{
  seating = new Stack<std::string>();
  line = new Queue<std::string>();
  command = "";
  name = "";
  takeASeat = "";
  num = 0;
  numPeople = 10;
}

void Theater::run(std::string filename)
{
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open() == true)
  {
    while(!inFile.eof())
    {
      if(inFile.eof() == true)
      {
        break;
        inFile.close();
      }
      command.clear();
      inFile >> command;
      if(command == "TICKET")
      {
        inFile >> name;
        try
        {
          line -> enqueue(name);
        }
        catch (PreconditionViolationException p)
        {
          std::cout << p.what() << "\n";
        }
      }
      else if(command == "SEATING")
      {
        while(line -> isEmpty() == false)
        {
            takeASeat = line->peekFront();
            try
            {
              line -> dequeue();
              std::cout << takeASeat << " left the ticket line.\n";
            }
            catch (PreconditionViolationException p)
            {
              std::cout << p.what() << "\n";
            }
            try
            {
              seating -> push(takeASeat);
            }
            catch (PreconditionViolationException p)
            {
              std::cout << p.what() << "\n";
            }
            numPeople--;
            if(numPeople == 0)
            {
              break;
            }
        }

      }
      else if(command == "EJECTION")
      {
        std::string nameeject = "";
        inFile >> num;
        for(int i = 1; i <= num; i++)
        {
          if(num > numPeople)
          {
            try
            {
              seating -> pop();
            }
            catch (PreconditionViolationException p)
            {
              std::cout << p.what() << "\n";
              break;
            }
            numPeople++;
          }
          else
          {
            std::string nameeject = "";
            try
            {
              nameeject = seating -> peek();
              seating -> pop();
              std::cout << nameeject << " left the theater. \n";
            }
            catch (PreconditionViolationException p)
            {
              std::cout << p.what() << "\n";
            }
            numPeople++;
          }
        }
      }
      else if(command == "CREDITS")
      {
        while(seating -> isEmpty() == false)
        {
          std::string nameleave = "";
          try
          {
            nameleave = seating -> peek();
            seating -> pop();
            std::cout << nameleave << " left the theater. \n";
          }
          catch (PreconditionViolationException p)
          {

            std::cout << p.what() << "\n";
          }
          numPeople++;
        }
      }
      else if(command == "STATUS")
      {
        std::string name1;
        std::string name2;
        std::cout << "\nWelcome to JayHawk Cineplex:\n";
        if(seating -> isEmpty() == true)
        {
          std::cout << "The theater is empty.\n";
          try
          {
            name1 = line -> peekFront();
            std::cout << name1 << " is next in the ticket line.\n";
          }
          catch (PreconditionViolationException p)
          {
            std::cout << p.what() << "\n";
          }
        }
        else
        {
          std::cout << "The theater is not empty.\n";
          try
          {
            name1 = line-> peekFront();
            std::cout << name1 << " is next in the ticket line.\n";
          }
          catch (PreconditionViolationException p)
          {
            std::cout << p.what() << "\n";
          }
          try
          {
            name2 = seating -> peek();
            std::cout << name2 << " will be the first person to leave the theater.\n";

          }
          catch (PreconditionViolationException p)
          {
            std::cout << p.what() << "\n";
          }
        }
        std::cout << "\n";
      }
    }
  }
}

Theater::~Theater()
{
  delete seating;
  delete line;
}
