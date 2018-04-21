/**
*	@file Package.h
*	@author Sahil Hirani
*	@date 04/21/2017
*	@brief Package header File
*/
#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
#include <iostream>

class Package
{
public:
  /** @pre None.
	*   @post Initializes private member variables
	*   @return None.
	*/
  Package();
  /** @pre None.
	*   @post Set priority member variable and priority int variable
	*   @return None.
	*/
  void setPriority(std::string priority);
  /** @pre None.
	*   @post Set contents member variable
	*   @return None.
	*/
  void setContents(std::string contents);
  /** @pre None.
	*   @post Set destination member variable
	*   @return None.
	*/
  void setDestination(std::string destination);
  /** @pre None.
	*   @post None
	*   @return Priority member variable.
	*/
  std::string getPriority() const;
  /** @pre None.
	*   @post None
	*   @return contents member variable.
	*/
  std::string getContents() const;
  /** @pre None.
	*   @post None
	*   @return destination member variable.
	*/
  std::string getDestination() const;
  /** @pre None.
	*   @post None
	*   @return priorityint member variable.
	*/
  int getPriorityint() const;
  /** @pre None.
	*   @post None
	*   @return true if the priorty is less than the other package
	*/
  bool operator<(const Package& rhs) const;
  /** @pre None.
	*   @post None
	*   @return true if the priorty is greater than the other package
	*/
  bool operator>(const Package& rhs) const;

private:
  int m_priorityint;
  std::string m_priority;
  std::string m_contents;
  std::string m_destination;
};

#endif
