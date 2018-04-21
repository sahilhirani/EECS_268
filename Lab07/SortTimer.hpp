/**
*	@file SortTimer.h
*	@author Sahil Hirani
*	@date 03/30/2017
*	@brief SortTimer class definition file
*/

#include <time.h>
#include <functional>

template <typename T>
double SortTimer<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
   //start a timer
   clock_t t = clock();
   //call the sort passed to us
   sort(arr, size);

   //stop the timer
   t = clock() - t;
   //return the time
   return(((double)t / CLOCKS_PER_SEC));
}
