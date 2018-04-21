/**
*	@file Theater.h
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief Theater class header file
*/
#ifndef THEATER_H
#define THEATER_H
#include "Stack.h"
#include "Queue.h"
#include "PreconditionViolationException.h"
#include <string>
#include <iostream>
#include <fstream>

class Theater
{
public:
  /** @pre None
	*   @post initializes private member variables
	*   @return None
	*/
  Theater();
  /** @pre None
	*   @post deletes stack and queue
	*   @return None
	*/
  ~Theater();
  /** @pre None
	*   @post runs entire program and reads in file
	*   @return None
	*/
  void run(std::string filename);

private:
  Stack<std::string>* seating;
  Queue<std::string>* line;
  std::string command;
  std::string name;
  std::string takeASeat;
  int num;
  int numPeople;

};

#endif
