/**
*	@file MazeWalker.cpp
*	@author Sahil Hirani
*	@date 03/17/2017
*	@brief MazeWalker class definition file
*/
#include "MazeWalker.h"

MazeWalker::MazeWalker(char** maze, int rows, int cols, int startr, int startc)
{
  counter = 0;
  isValid = false;
  m_maze = maze;
  m_row = rows;
  m_col = cols;
  m_startRow = startr;
  m_startCol = startc;
  m_mazeCheck = new int*[m_row];
  for(int i = 0; i < m_row; i++)
  {
    m_mazeCheck[i] = new int[m_col];
  }
  for(int i = 0; i < m_row; i++)
  {
    for(int j = 0; j < m_col; j++)
    {
      m_mazeCheck[i][j] = 0;
    }
  }
  recStarter();
}

int** MazeWalker::getOutputArr()
{
  return(m_mazeCheck);
}

bool MazeWalker::getisValid() throw(PreconditionViolationException)
{
  if(isValid == true)
  {
    return(true);
  }
  else
  {
    throw PreconditionViolationException("No Way Out!");
  }
}

void MazeWalker::recStarter()
{
  recTraverse(m_startRow, m_startCol);
}

void MazeWalker::recTraverse(int row, int col)
{
  counter++;
  if(row >= 0 && col >= 0 && row <= m_row && col <= m_col)
  {
    if(m_maze[row][col] == 'X')
    {
      counter--;
    }
    else if(m_mazeCheck[row][col] > 0)
    {
      counter--;
      //m_mazeCheck[row][col] = 0;
    }
    else if(m_maze[row][col] == ' ')
    {
      for(int i = 0; i < m_row; i++)
      {
        for(int j = 0; j <  m_col; j++)
        {
          if(m_mazeCheck[i][j] >= counter)
          {
            m_mazeCheck[i][j] = 0;
          }
        }
      }
      m_mazeCheck[row][col] = counter;
      recTraverse(row-1,col);
      recTraverse(row, col +1);
      recTraverse(row+1, col);
      recTraverse(row, col-1);
      counter--;
    }
    else if(m_maze[row][col] == 'E')
    {
      m_mazeCheck[row][col] = counter;
      isValid = true;
    }
  }
  else
  {
    counter--;
  }
}

MazeWalker::~MazeWalker()
{
  for(int i = 0; i < m_row; i++)
  {
      delete[] m_mazeCheck[i];
  }
  delete[] m_mazeCheck;
}
