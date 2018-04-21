/**
*	@file Stack.h
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief Stack class header file
*/

#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include <string>
#include <iostream>

template <typename T>
class Stack: public StackInterface<T>
{
public:
  /** @pre None
  	*   @post Initializes private member variables
  	*   @return None
  	*/
  Stack();
  /** @pre None
  	*   @post deletes(pops) all nodes in stack
  	*   @return None
  	*/
  ~Stack();
  /** @pre None
  	*   @post None
  	*   @return True or False if stack is empty
  	*/
  bool isEmpty() const;
  /** @pre None
  	*   @post Takes in a T value and adds to the stack
  	*   @return None or exception
  	*/
  void push(const T value) throw(PreconditionViolationException);
  /** @pre None
  	*   @post deletes top node from stack
  	*   @return None or exception
  	*/
  void pop() throw(PreconditionViolationException);
  /** @pre None
  	*   @post none
  	*   @return top Value of stack or Exception
  	*/
  T peek() const throw(PreconditionViolationException);

protected:
  int m_size;
  int m_maxsize;
  Node<T>* m_top;
};

#include "Stack.hpp"
#endif
