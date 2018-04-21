/**
*	@file Warehouse.cpp
*	@author Sahil Hirani
*	@date 05/02/2017
*	@brief Warehouse definition File
*/
#include "Warehouse.h"

Warehouse::Warehouse()
{
  delivery = new Heap<Package>();
}

Warehouse::~Warehouse()
{
  delete delivery;
}

void Warehouse::truck(int numpack)
{
  std::cout <<"Truck has arrived!\n";
  std::cout <<"Loading the following packages:\n";
  for(int i = 0; i < numpack; i++)
  {
    if(delivery -> size() == 0)
    {
      break;
    }
    else
    {
      try
      {
        Package temp = (delivery -> peekTop());
        std::cout << i+1 <<". Priority: " << temp.getPriority() <<"; Contents: " << temp.getContents() << "; Destination: " << temp.getDestination() << "\n";
        delivery -> remove();

      }
      catch(Exception e)
      {
        std::cout << e.what() << "\n";
        break;
      }
    }
  }
  std::cout <<"Truck is Leaving!\n";
}

void Warehouse::run(std::string filename)
{
  std::string priority;
  std::string contents;
  std::string destination;
  std::string numpack;
  int numpackint;
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open() == true)
  {
    while(!inFile.eof())
    {
      if(inFile.eof() == true)
      {
        break;
      }
      std::getline(inFile, priority, ',');
      if(priority == "TRUCK")
      {
        std::getline(inFile, numpack);
        numpackint = std::stoi(numpack);
        truck(numpackint);
      }
      else
      {
        std::getline(inFile, contents, ',');
        std::getline(inFile, destination, '\n');
        Package tempadd;
        tempadd.setDestination(destination);
        tempadd.setContents(contents);
        tempadd.setPriority(priority);

        delivery -> add(tempadd);
      }
      priority.clear();
      contents.clear();
      destination.clear();
      numpack.clear();
      numpackint = 0;
    }
  }
  else
  {
    std::cout <<"Filename is not correct, cannot open file! Ending Program!\n";
    return;
  }
  inFile.close();
}
