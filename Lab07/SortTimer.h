/**
*	@file SortTimer.h
*	@author Sahil Hirani
*	@date 03/30/2017
*	@brief SortTimer class header file
*/

#ifndef SORT_TIMER_H
#define SORT_TIMER_H
#include <time.h>
#include <functional>
#include "Sorts.h"

template <typename T>
class SortTimer
{

public:
  /** @pre None.
	*   @post Calculate time of sorting functions
	*   @return time of sorting method type double
	*/
  static double sortTimer(std::function<void(T[], int)> sort, T arr[], int size);

private:

};

#include "SortTimer.hpp"

#endif
