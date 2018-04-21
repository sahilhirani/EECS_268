/**
*	@file QueueInterface.h
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief QueueInterface class header file
*/

#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H
#include "PreconditionViolationException.h"

template <typename T>
class QueueInterface
{
public: // All Pre post return comments are in Queue.h these are all pure virtual methods that are not defined yet
  virtual ~QueueInterface(){};
  virtual bool isEmpty() const = 0;
  virtual void enqueue(const T value) throw(PreconditionViolationException) = 0;
  virtual void dequeue() throw(PreconditionViolationException) = 0;
  virtual T peekFront() const throw(PreconditionViolationException) = 0;

protected:

};

#endif
