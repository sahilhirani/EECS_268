/**
*	@file main.cpp
*	@author Sahil Hirani
*	@date 03/30/2017
*	@brief main file for Lab 7
*/

#include <iostream>
#include <fstream>
#include <string>
#include "SortTimer.h"


int main(int argc, char* argv[])
{
  if(argc < 5) //Checks to see if a file name was given
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    std::cout.setf(std::ios::fixed);
	  std::cout.setf(std::ios::showpoint);
    std::cout.precision(6);
    std::string sortMethod = argv[1];
    std::string a = argv[2];
    std::string b = argv[3];
    std::string c = argv[4];
    std::string fileName = argv[5];
    int start = stoi(a);
    int end = stoi(b);
    int jump = stoi(c);
    int size = end;
    if((end < start) || (jump > size) || (start < 0))
    {
      std::cout<<"Invalid starting/ending/bounded values! \n";
      return(0);
    }
    int* array = new int[size];
    //initialize random seed
    srand(time(NULL));
    // generate value between start and ending value
    for(int i = 0; i < size; i++)
    {
      array[i]=rand() % (end-start) + start;
    }
    //open ofstream
    std::ofstream outFile(fileName);
    if(outFile.is_open())
    {
      // timing for bubble sort
      if(sortMethod == "bubble")
      {
        outFile << "bubbleSort" << std::endl;
        for(int i = 0; i < size; i = i + jump)
        {
          outFile << start + i << ", " << SortTimer<int>::sortTimer(Sorts<int>::bubbleSort, array, i) << std::endl;
        }
      }
  //timing for selection sort
    else if(sortMethod == "selection")
    {
      outFile << "SelectionSort" << std::endl;
      for(int i = 0; i < size; i = i + jump)
      {
        outFile << start + i << ", " << SortTimer<int>::sortTimer(Sorts<int>::selectionSort, array, i) << std::endl;
      }
    }
    //timing for insertion sort
    else if (sortMethod == "insertion")
    {
      outFile << "insertionSort" << std::endl;
      for(int i = 0; i < size; i = i + jump)
      {
        outFile << start + i << ", " << SortTimer<int>::sortTimer(Sorts<int>::insertionSort, array, i) << std::endl;
      }
    }
    //for merge sort
    else if (sortMethod == "merge")
    {
      outFile << "mergeSort" << std::endl;
      for(int i = 0; i < size; i = i + jump)
      {
        outFile << start + i << ", " << SortTimer<int>::sortTimer(Sorts<int>::mergeSort, array, i) << std::endl;
      }
    }
    //for quick sort
    else if (sortMethod == "quick")
    {
      outFile << "quickSort" << std::endl;
      for(int i = 0; i < size; i = i + jump)
      {
        outFile << start + i << ", " << SortTimer<int>::sortTimer(Sorts<int>::quickSort, array, i) << std::endl;
      }
    }
    //for quick sort with median
    else if (sortMethod == "quickSortWithMedian")
    {
      outFile << "quickSortWithMedian" << std::endl;
      for(int i = 0; i < size; i = i + jump)
      {
        outFile << start + i << ", " << SortTimer<int>::sortTimer(Sorts<int>::quickSortWithMedian, array, i) << std::endl;
      }
    }
    else
    {
      std::cout<<"Invalid sort method! \n";
    }
    outFile.close();
    }
    delete[] array;
  }

  return(0);
}
