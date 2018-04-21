/**
*	@file Exception.cpp
*	@author Sahil Hirani
*	@date 04/14/2017
*	@brief exception class definition file
*/
#include "Exception.h"

Exception::Exception(const char* msg) : std::runtime_error(msg)
{

}
