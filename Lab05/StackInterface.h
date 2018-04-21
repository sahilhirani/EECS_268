/**
*	@file StackInterface.h
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief StackInterface class header file
*/

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H
#include "PreconditionViolationException.h"

template <typename T>
class StackInterface
{

public: // All Pre post return comments are in Stack.h these are all pure virtual methods that are not defined yet
  virtual ~StackInterface(){};
  virtual bool isEmpty() const = 0;
  virtual void push(const T value) throw(PreconditionViolationException) = 0;
  virtual void pop() throw(PreconditionViolationException) = 0;
  virtual T peek() const throw(PreconditionViolationException) = 0;

protected:

};

#endif
