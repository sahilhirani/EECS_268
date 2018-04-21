/**
*	@file Stack.hpp
*	@author Sahil Hirani
*	@date 03/03/2017
*	@brief Stack class defenition file
*/

template <typename T>
Stack<T>::Stack()
{
  m_size = 0;
  m_maxsize = 10; //Size of seating in the theater minus 1 because stack starts at 0
  m_top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
  while(isEmpty() != true)
  {
    try
    {
      pop();
    }
    catch (PreconditionViolationException e)
    {
      std::cout << e.what() << "\n";
      break;
    }
  }
}

template <typename T>
bool Stack<T>::isEmpty() const
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
void Stack<T>::push(const T value) throw(PreconditionViolationException)
{
  Node<T>* temp = new Node<T>(value);
  if(m_size == 0)
  {
    m_top = temp;
    m_size++;
  }
  else if(m_size == m_maxsize)
  {
    delete temp;
    throw PreconditionViolationException("Theater is full! Cannot add any more people until someone leaves.");
  }
  else
  {
    temp -> setNext(m_top);
    m_top = temp;
    m_size++;
  }
}

template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
  if(m_size == 0)
  {
    throw PreconditionViolationException("Pop attempted on an empty stack");
  }
  else if(m_size == 1)
  {
    delete m_top;
    m_size--;
  }
  else
  {
    Node<T>* temp = m_top -> getNext();
    delete m_top;
    m_top = temp;
    m_size--;
  }
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
  if(m_size == 0)
  {
    throw PreconditionViolationException("Peek attempted on an empty stack");
  }
  else
  {
    Node<T>* temp = m_top;
    return(temp -> getValue());
  }
}
