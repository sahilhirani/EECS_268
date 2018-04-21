/**
*	@file MazeReader.cpp
*	@author Sahil Hirani
*	@date 03/17/2017
*	@brief MazeReader class definition file 
*/
#include "MazeReader.h"

MazeReader::MazeReader()
{
  m_numRows = 0;
  m_numCols = 0;
  startRow = 0;
  startCol = 0;
  m_maze = nullptr;
  fileValid = false;
  deletearray = false;
}

void MazeReader::run(std::string filename) throw(PreconditionViolationException)
{
  std::string temp;
  std::string trash;
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open() == false)
  {
    throw PreconditionViolationException("File was not able to be opened!");
  }
  else
  {
    inFile >> m_numRows;
    inFile >> m_numCols;
    inFile >> startRow;
    inFile >> startCol;
    if((m_numRows <= 0) || (m_numCols <= 0))
    {
      throw PreconditionViolationException("Invalid Array Row or Column Size!");
    }
    else if((startRow < 0) || (startRow >= m_numRows) || (startCol < 0) || (startCol >= m_numCols))
    {
      throw PreconditionViolationException("Invalid Starting Position!");
    }
    m_maze = new char*[m_numRows];
    for(int i = 0; i < m_numRows; i++)
    {
      m_maze[i] = new char[m_numCols];
    }
    deletearray = true;
    std::getline(inFile, trash, '\n'); // gets rid of empty infile line
    for(int i = 0; i < m_numRows; i++)
    {
      temp.clear();
      std::getline(inFile, temp, '\n');
      for(int j = 0; j < m_numCols; j++)
      {
        m_maze[i][j] = temp[j];
      }
    }
    for(int i = 0; i < m_numRows; i++)
    {
      for(int j = 0; j < m_numCols; j++)
      {
        if(m_maze[i][j] == 'E')
        {
          fileValid = true;
        }
        else
        {

        }
      }
    }
    if(fileValid == false)
    {
      throw PreconditionViolationException("No Exit \'E\' in Maze! File Invalid!");
    }
  }

}

char** MazeReader::getMaze()
{
  return(m_maze);
}

int MazeReader::getRow()
{
  return(m_numRows);
}

int MazeReader::getCol()
{
  return(m_numCols);
}

int MazeReader::getStartRow()
{
  return(startRow);
}
int MazeReader::getStartCol()
{
  return(startCol);
}

MazeReader::~MazeReader()
{
  if(deletearray == true)
  {
    for(int i = 0; i < m_numRows; i++)
    {
      delete[] m_maze[i];
    }
    delete[] m_maze;
  }
  else
  {

  }
}
