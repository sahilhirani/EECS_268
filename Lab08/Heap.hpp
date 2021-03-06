/**
*	@file Heap.hpp
*	@author Sahil Hirani
*	@date 04/21/2017
*	@brief Heap definition File
*/
template <typename T>
Heap<T>::Heap()
{
  m_arrSize = 2;
  m_heapSize = 0;
  m_arr = new T[2];
}

template <typename T>
Heap<T>::~Heap()
{
  delete[] m_arr;
}

template <typename T>
bool Heap<T>::isEmpty() const
{
  if(m_heapSize == 0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

template <typename T>
int Heap<T>::size() const
{
  return(m_heapSize);
}

template <typename T>
void Heap<T>::add(T value)
{
  if(m_arrSize == m_heapSize)
  {
    resize();
  }
  m_heapSize++;
  m_arr[m_heapSize-1] = value;
  upHeap(m_heapSize-1);
}

template <typename T>
void Heap<T>::remove() throw(Exception)
{
  if(m_heapSize == 0)
  {
    throw Exception("Empty");
  }
 else if(m_heapSize == 1)
  {
    m_heapSize = 0;
  }
  else if(m_heapSize == 2)
  {
    std::swap(m_arr[0], m_arr[m_heapSize-1]);
    m_heapSize--;
    downHeap(0);
  }
  else
  {
    std::swap(m_arr[0], m_arr[m_heapSize-1]);
    m_heapSize--;
    downHeap(0);
  }
}

template <typename T>
T Heap<T>::peekTop() const throw(Exception)
{
  if(m_heapSize == 0)
  {
    throw Exception("Heap is Empty\n");
  }
  return(m_arr[0]);
}

template <typename T>
void Heap<T>::upHeap(int index)
{
  if((isEmpty() == true) || (m_heapSize == 1))
  {}
  else
  {
    int pindex = ((index - 1)/2);
    if(pindex < m_heapSize && index < m_heapSize)
    {
      if(m_arr[pindex] > m_arr[index])
      {
        std::swap(m_arr[pindex], m_arr[index]);
        upHeap(pindex);
      }
    }
  }
}

template <typename T>
void Heap<T>::downHeap(int index)
{
  int left = ((2 * index) + 1);
  int right = ((2 * index) + 2);
  if(left < m_heapSize)
  {
    if(right < m_heapSize)
    {
      if((m_arr[left] < m_arr[right]) && (m_arr[left] < m_arr[index]))
      {
        T temp;
        temp = m_arr[left];
        m_arr[left] = m_arr[index];
        m_arr[index] = temp;
        downHeap(left);
      }
      else if((m_arr[right] < m_arr[left]) && (m_arr[right] < m_arr[index]))
      {
        T temp;
        temp = m_arr[right];
        m_arr[right] = m_arr[index];
        m_arr[index] = temp;
        downHeap(right);
      }
    }
    else if(m_arr[index] > m_arr[left])
    {
      T temp;
      temp = m_arr[left];
      m_arr[left] = m_arr[index];
      m_arr[index] = temp;
    }
    else
    {
      return;
    }
  }
}

template <typename T>
void Heap<T>::resize()
{
  m_arrSize = m_arrSize * 2;
  T* tempArr = new T[m_arrSize];
  for(int i = 0; i < ((m_arrSize/2)); i++)
  {
    tempArr[i] = m_arr[i];
  }
  delete[] m_arr;
  m_arr = tempArr;
}
