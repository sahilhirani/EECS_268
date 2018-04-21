/**
*	@file Executive.cpp
*	@author Sahil Hirani
*	@date 03/17/2017
*	@brief Executive class definition file 
*/
#include "Executive.h"
#include <string>

Executive::Executive()
{
  arrayOutput = nullptr;
  m_row = 0;
  m_col = 0;
}

Executive::~Executive()
{

}

void Executive::run(std::string filename)
{
  MazeReader mazereader;
  bool broken = false;
  try
  {
    mazereader.run(filename);
  }
  catch (PreconditionViolationException e)
  {
    std::cout << e.what() << "\n";
    broken = true;
  }
  if(broken == false)
  {
    char** mazeinput = mazereader.getMaze();
    m_row = mazereader.getRow();
    m_col = mazereader.getCol();
    startrow = mazereader.getStartRow();
    startcol = mazereader.getStartCol();
    MazeWalker traverse(mazeinput, m_row, m_col, startrow, startcol); // automatically traverses
    try
    {
      traverse.getisValid();
      broken = false;
    }
    catch (PreconditionViolationException e)
    {
      std::cout << "Starting Position: " << startrow << "," << startcol << "\n";
      std::cout << "Size: " << m_row << "," << m_col << "\n";
      std::cout << e.what() << "\n";
      broken = true;
    }
    if(broken == false)//CONTINUES PROGRAM IF NO EXCEXPTION IS THROWN
    {
      arrayOutput = traverse.getOutputArr();
      std::cout << "Starting Position: " << startrow << "," << startcol << "\n";
      std::cout << "Size: " << m_row << "," << m_col << "\n";
      for(int i = 0; i < m_row; i++)
      {
        for(int j = 0; j < m_col; j++)
        {
          std::cout << arrayOutput[i][j] << "\t";
        }
        std::cout << "\n";
      }
      std::cout << "We Escaped!\n";
    }
    else if(broken == true)
    {
      //again stops broken due to some issue in maze walker(traverses the maze) thrown exception
    }
  }
  else if(broken == true)
  {
    //stops the program here after printing out the exception, if exception is thrown this means something went wrong when reading in the file
  }
}
