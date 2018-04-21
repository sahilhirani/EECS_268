/**
*	@file Executive.cpp
*	@author Sahil Hirani
*	@date 02/09/2017
*	@brief A clas defenition file for Executive class (RUNS INTERACTIVE MENU FOR USERS HERE)
*/
#include "Executive.h"

void Executive::run()
{
  LinkedList<int> myList;
  int choice = 0;
  while(choice != 8)
  {
    std::cout << "Make a Selection:" << "\n"
              << "1) Add Front" << "\n"
              << "2) Add Back" << "\n"
              << "3) Remove front\n"
              << "4) Remove back\n"
              << "5) Insert value at position\n"
              << "6) Print length\n"
              << "7) Print list\n"
              << "8) Exit\n";
    std::cout << "Choice:";
    std::cin >> choice;
    std::cout << "\n";
    if(choice == 1)
    {
      std::cout <<"Value:";
      int value = 0;
      std::cin >> value;
      myList.addFront(value);
      std::cout <<"Front added!\n";
      std::cout <<"\n";
    }
    else if(choice == 2)
    {
      std::cout <<"Value?:";
      int value = 0;
      std::cin >> value;
      myList.addBack(value);
      std::cout <<"Back added!\n";
      std::cout <<"\n";
    }
    else if(choice == 3)
    {
      bool rm = myList.removeFront();

      if(rm == true)
      {
        std::cout << "Successfully Removed!\n";
      }
      else
      {
        std::cout << "Not Successfully Removed\n";
        bool empty = myList.isEmpty();
        if(empty == true)
        {
          std::cout << "List is Empty, add a front before you try to remove one!\n";
        }
        else
        {
          std::cout <<"Broken Function!\n";
        }
      }
      std::cout <<"\n";
    }
    else if(choice == 4)
    {
      bool rm = myList.removeBack();
      if(rm == true)
      {
        std::cout <<"Successfully Removed!\n";
      }
      else
      {
        std::cout << "Not Successfully Removed\n";
        bool empty = myList.isEmpty();
        if(empty == true)
        {
          std::cout << "List is Empty, add a front before you try to remove one!\n";
        }
        else
        {
          std::cout <<"Broken Function!\n";
        }
      }
      std::cout <<"\n";
    }
    else if(choice == 5)
    {
      int pos = 0;
      int value = 0;
      std::cout << "Insert a Position in the linked list(Starting index is 1):";
      std::cin >> pos;
      if((pos > 0) && (pos <= myList.getLength()))
      {
        std::cout << "Insert a value:";
        std::cin >> value;
        bool work = myList.insert(pos, value);
        if(work == true)
        {
          std::cout <<"Insert done!\n";
        }
        else
        {
          std::cout <<"not working!";
        }
      }
      else
      {
        std::cout << "Position not valid!\n";
      }
      std::cout <<"\n";
    }
    else if(choice == 6)
    {
      std::cout << "The length of the LinkedList is currently " << myList.getLength() << "\n";
      std::cout <<"\n";
    }
    else if(choice == 7)
    {
      std::cout <<"Your List:\n";
      for(int i = 1; i <= myList.getLength(); i++)
      {
        std::cout << myList.getEntry(i) << "\n";
      }
      std::cout <<"\n";
    }
    else if(choice == 8)
    {
      std::cout <<"Exiting!\n";
      std::cout <<"\n";
    }
    else
    {
      std::cout << "Not a valid input! Try Again!\n";
    }
  }
}
