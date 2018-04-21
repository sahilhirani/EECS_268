/**
*	@file MazeWalker.h
*	@author Sahil Hirani
*	@date 03/17/2017
*	@brief MazeWalker class header file
*/
#ifndef MAZE_WALKER_H
#define MAZE_WALKER_H
#include "MazeReader.h"
#include "PreconditionViolationException.h"
#include <iostream>


class MazeWalker
{
public:

  /** @pre None.
	*   @post Initialize member variables and creates output array of 0's
	*   @return None.
	*/
  MazeWalker(char** maze, int rows, int cols, int startr, int startc); //initializes variables
  /** @pre None.
	*   @post deallocates arrays
	*   @return None.
	*/
  ~MazeWalker();//deletes arrays
  /** @pre None.
	*   @post None.
	*   @return treturns outputarray
	*/
  int** getOutputArr();
  /** @pre None.
	*   @post None.
	*   @return true if valid is true otherwise it throws an "array invalid" exception
	*/
  bool getisValid() throw(PreconditionViolationException);
  /** @pre None.
	*   @post Recursivley goes through maze and also kees track in mazechecker
	*   @return None.
	*/
  void recTraverse(int row, int col);
  /** @pre None.
	*   @post Starts recursive function call
	*   @return None.
	*/
  void recStarter();



private:
  char** m_maze = nullptr;
  int** m_mazeCheck = nullptr;
  int m_row;
  int m_col;
  int m_startRow;
  int m_startCol;
  bool isValid;
  int counter;
};

#endif
