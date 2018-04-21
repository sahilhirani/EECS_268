/**
*	@file MazeReader.h
*	@author Sahil Hirani
*	@date 03/17/2017
*	@brief MazeReader class header file
*/

#ifndef MAZE_READER_H
#define MAZE_READER_H
#include "PreconditionViolationException.h"
#include <string>
#include <fstream>

class MazeReader
{

public:
  /** @pre None.
	*   @post Initializes all private member variables
	*   @return None.
	*/
  MazeReader();
  /** @pre None.
	*   @post Reads in file into assorted private member variables
	*   @return throws an exception if there are errors in the file
	*/
  void run(std::string filename) throw(PreconditionViolationException);
  /** @pre None.
	*   @post None.
	*   @return returns maze that is inputed from file
	*/
  char** getMaze();
  /** @pre None.
	*   @post None.
	*   @return Rreturns number of rows in array
	*/
  int getRow();
  /** @pre None.
	*   @post None.
	*   @return Returns number of columns in array
	*/
  int getCol();
  /** @pre None.
	*   @post None.
	*   @return returns starting row position
	*/
  int getStartRow();
  /** @pre None.
	*   @post None.
	*   @return starting column position
	*/
  int getStartCol();
  /** @pre None.
	*   @post Deallocates array
	*   @return None.
	*/
  ~MazeReader();

private:
  char** m_maze;
  int m_numRows;
  int m_numCols;
  int startRow;
  int startCol;
  bool fileValid;
  bool deletearray;

};

#endif
