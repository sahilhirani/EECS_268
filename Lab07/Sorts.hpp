/**
*	@file Sorts.hpp
*	@author Sahil Hirani
*	@date 03/30/2017
*	@brief Sorts class definition file
*/

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
  //T temp;
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(arr[j] > arr[j+1])
      {
        /*temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;*/
        std::swap(arr[j], arr[j+1]);
      }
    }
  }
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = size-1; j > i; j--)
    {
      if(arr[i] > arr[j])
      {
        std::swap(arr[i], arr[j]);
      }
    }
  }
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
  int pos = 1;
  for (int i = 0; i < size; i++)
  {
    for(int j = pos; j > 0; j--)
    {
      if(arr[j] > arr[j-1])
      {
        std::swap(arr[j], arr[j-1]);
      }
    }
    pos++;
  }
}

template <typename T>
void Sorts<T>::merge(T arr[], T* a1, T* a2, int size1, int size2)
{
  T temp[size1 + size2];// the temp array
  int left, right, k;
  left = 0; right = 0; k = 0;
  while(left < size1 && right < size2){
  //re-connect elements depend on the value of each sides
    if(a1[left] < a2[right])
      temp[k++] = a1[left++];
    else
      temp[k++] = a2[right++];
  }
  while(left < size1)
    temp[k++] = a1[left++];
  while(right < size2)
    temp[k++] = a2[right++];
  //copy data back to the array
  for(int x = 0; x < size1+size2; x++)
    arr[x] = temp[x];
}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
  if(size > 1){
    //sort the left
    mergeSort(arr, size / 2);
    //sort the right
    mergeSort(arr + (size / 2), size - (size / 2));
    //merge until the size of each element is one
    merge(arr, arr, arr + (size / 2), size / 2, size - (size / 2));
  }
}


template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
  int mid = (last+1)/2;
  if(arr[first]>arr[last]) std::swap(arr[first], arr[last]);
  if(arr[mid]<arr[last]) std::swap(arr[first], arr[last]);
  if(arr[first]>arr[last]) std::swap(arr[first], arr[last]);
}

template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
  if(median) setMedianPivot(arr, first, last);
  int a = first;
  for(int i= first; i<last; i++)
  {
    if(arr[i]<arr[last]){
    std::swap(arr[i], arr[a]);
    a++;
    }
  }
  //swap the pivot to the last position
  std::swap(arr[a], arr[last]);
  return a;
}

template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{//sorting for each side of the array
  if(first<last)
  {
    int pivot = partition(arr, first, last, median);
    //sort for the right
    quickSortRec(arr, pivot+1, last, median);
    quickSortRec(arr, first, pivot-1, median);//sort for the left
  }
}

template<typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
  quickSortRec(arr, 0, size-1, false);
}

template<typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
  quickSortRec(arr, 0, size-1, true);
}
