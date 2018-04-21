/**
*	@file Warehouse.h
*	@author Sahil Hirani
*	@date 04/21/2017
*	@brief Warehouse class header File
*/
#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "Package.h"
#include "Heap.h"
#include "Exception.h"
#include <string>
#include <iostream>
#include <fstream>


class Warehouse
{
public:
  /** @pre None.
	*   @post Creates new memory allocation of heap member variable
	*   @return None.
	*/
  Warehouse();
  /** @pre None.
	*   @post Deletes memory allocation of heap member variable
	*   @return None.
	*/
  ~Warehouse();
  /** @pre None.
	*   @post Runs through program (reading in file etc.)
	*   @return None.
	*/
  void run(std::string filename);
  /** @pre None.
	*   @post Prints out the list of things added to the truck and shipped out of the warehouse and removes these packages from the heap
	*   @return None.
	*/
  void truck(int numpack);


private:
  Heap<Package>* delivery;

};

#endif
