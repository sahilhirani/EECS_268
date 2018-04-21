/**
*	@file PreconditionViolationException.cpp
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief exception class definition file
*/
#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg) : std::runtime_error(msg)
{

}
