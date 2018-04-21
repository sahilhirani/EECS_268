/**
*	@file Queue.hpp
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief Queue class defenition file
*/

template <typename T>
Queue<T>::Queue()
{
  m_size = 0;
  m_front = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
  while(isEmpty() != true)
  {
    try
    {
      dequeue();
    }
    catch (PreconditionViolationException e)
    {
      std::cout << e.what() << "\n";
      break;
    }
  }
}

template <typename T>
bool Queue<T>::isEmpty() const
{
  if(m_size == 0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

template <typename T>
void Queue<T>::enqueue(const T value) throw(PreconditionViolationException)
{
  if(m_size == 0)
  {
    Node<T>* newNode = new Node<T>(value);
    m_front = newNode;
    m_size++;
  }
  else if(m_size > 0)
  {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = m_front;
    while(temp -> getNext() != nullptr)
    {
      temp = temp -> getNext();
    }
    temp -> setNext(newNode);
    m_size++;
  }
  else
  {
    throw PreconditionViolationException("Enqueue Attempted and Failed! Shouldn't happen!");
  }
}

template <typename T>
void Queue<T>::dequeue() throw(PreconditionViolationException)
{
  Node<T>* temp = m_front -> getNext();
  if(m_size == 0)
  {
    throw PreconditionViolationException("Dequeue attempted on empty Queue!");
  }
  else
  {
    delete m_front;
    m_front = temp;
    m_size--;
  }
}

template <typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
  if(m_size == 0)
  {
    throw PreconditionViolationException("Peek attempted on Empty Queue!");
  }
  else
  {
    return(m_front -> getValue());
  }
}
