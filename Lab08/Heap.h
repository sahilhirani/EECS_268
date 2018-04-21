/**
*	@file Heap.h
*	@author Sahil Hirani
*	@date 04/21/2017
*	@brief Heap header File
*/
#ifndef HEAP_H
#define HEAP_H
#include "HeapInterface.h"
#include <iostream>


template <typename T>
class Heap: public HeapInterface<T>
{
public:
  /** @pre None.
	*   @post Initializes member variables and creates a T array of size 2
	*   @return None.
	*/
  Heap();
  /** @pre None.
	*   @post deletes the m_arr member variable
	*   @return None.
	*/
  ~Heap();
  /** @pre None.
	*   @post None.
	*   @return true if heap is empty
	*/
  bool isEmpty() const;
  /** @pre None.
	*   @post None.
	*   @return heap size
	*/
  int size() const;
  /** @pre None.
	*   @post Adds the value to the heap
	*   @return None.
	*/
  void add(T value);
  /** @pre None.
	*   @post removes root value from the heap
	*   @return None.
	*/
  void remove() throw(Exception);
  /** @pre None.
	*   @post None.
	*   @return Root Value
	*/
  T peekTop() const throw(Exception);

protected:
  /** @pre None.
	*   @post upheaps the given index to the correct placement in the heap
	*   @return None.
	*/
  void upHeap(int index);
  /** @pre None.
  *   @post downheaps the given index to the correct placement in the heap
  *   @return None.
  */
  void downHeap(int index);
  /** @pre None.
  *   @post doubles the size of the array
  *   @return None.
  */
  void resize();
  int m_arrSize;
  int m_heapSize;
  T* m_arr;



};

#include "Heap.hpp"
#endif
