/**
*	@file Executive.h
*	@author Sahil Hirani
*	@date 03/17/2017
*	@brief Executive class header file
*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "MazeReader.h"
#include "MazeWalker.h"
#include "PreconditionViolationException.h"
#include <string>
#include <iostream>

class Executive
{
public:
  /** @pre None.
	*   @post None.
	*   @return true if the list is empty, false otherwise.
	*/
  Executive();
  /** @pre None.
	*   @post None.
	*   @return true if the list is empty, false otherwise.
	*/
  ~Executive();
  /** @pre None.
	*   @post None.
	*   @return true if the list is empty, false otherwise.
	*/
  void run(std::string filename);


private:
  int** arrayOutput;
  int m_row;
  int m_col;
  int startrow;
  int startcol;
};

#endif
