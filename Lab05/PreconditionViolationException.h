/**
*	@file PreconditionViolationException.h
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief exception class header file
*/
#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXCEPTION_H
#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
public:
  /** @pre None
	*   @post Takes in a char* and sends it to runtime_error
	*   @return None
	*/
  PreconditionViolationException(const char* msg);
};

#endif
