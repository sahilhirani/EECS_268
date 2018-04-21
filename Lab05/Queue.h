/**
*	@file Queue.h
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief Queue class header file
*/
#ifndef QUEUE_H
#define QUEUE_H
#include "QueueInterface.h"
#include "Node.h"
#include <string>
#include <iostream>

template <typename T>
class Queue: public QueueInterface<T>
{

public:
  /** @pre None
  	*   @post Initializes private member variables
  	*   @return None
  	*/
  Queue();
  /** @pre None
  	*   @post TDeletes nodes in queue
  	*   @return None
  	*/
  ~Queue();
  /** @pre None
  	*   @post None
  	*   @return True or False if queue is empty
  	*/
  bool isEmpty() const;
  /** @pre None
  	*   @post Takes in a T value and adds to the queue
  	*   @return None or exception
  	*/
  void enqueue(const T value) throw(PreconditionViolationException);
  /** @pre None
  	*   @post deletes first node in queue
  	*   @return None or Exception
  	*/
  void dequeue() throw(PreconditionViolationException);
  /** @pre None
  	*   @post none
  	*   @return Front Value of Queue or Exception
  	*/
  T peekFront() const throw(PreconditionViolationException);

protected:
  int m_size;
  Node<T>* m_front;

};

#include "Queue.hpp"
#endif
