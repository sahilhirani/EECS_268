/**
*	@file Sorts.h
*	@author Sahil Hirani
*	@date 03/30/2017
*	@brief Sorts class header file
*/
#ifndef SORTS_H
#define SORTS_H
#include <iostream>

template <typename T>
class Sorts
{
public:
  static void bubbleSort(T arr[], int size);
  static void selectionSort(T arr[], int size);
  static void insertionSort(T arr[], int size);
  static void mergeSort(T arr[], int size);
  static void quickSort(T arr[], int size);
  static void quickSortWithMedian(T arr[], int size);

private:

  static void merge(T arr[], T* a1, T* a2, int size1, int size2);
  static void quickSortRec(T arr[], int first, int last, bool median);
  static void setMedianPivot(T arr[], int first, int last);
  static int partition(T arr[], int first, int last, bool median);


};

#include "Sorts.hpp"
#endif
