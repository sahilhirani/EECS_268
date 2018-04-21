/**
*	@file LinkedListTester.cpp
*	@author Sahil Hirani
*	@date 02/09/2017
*	@brief A class defenition file for LinkedListTester class
*/

#include "LinkedListTester.h"
#include "LinkedList.h"
LinkedListTester::LinkedListTester()
{

}
void LinkedListTester::runTests()
{
  test01();
  test02();
  test03();
  test04();
  test05();
  test06();
  test07();
  test08();
  test09();
  test10();
  test11();
  test12();
  test13();
  test14();
  test15();
  test16();
}

void LinkedListTester::test01()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #1: size of empty list is zero ";
  if (LinkList.isEmpty() == true)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test02()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #2: size returns correct value after 1 addFront ";
  LinkList.addFront(1);
  if ((LinkList.isEmpty() == false) && (LinkList.getLength() == 1))
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test03()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #3: size returns correct value after 1 addBack  ";
  LinkList.addBack(3);
  ;
  if( LinkList.getLength() == 1)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test04()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #4: size returns correct value after multiple addFront ";
  for(int i = 1; i <= 5; i++)
  {
    LinkList.addFront(2);
  }
  if( LinkList.getLength() == 5)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test05()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #5: size returns correct value after multiple addBack ";
  for(int i = 1; i <= 5; i++)
  {
    LinkList.addBack(1);
    ;
  }
  if( LinkList.getLength() == 5)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test06()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #6: size returns correct value after adds and removeFront ";
  LinkList.addFront(1);
  LinkList.removeFront();
  if(LinkList.getLength() == 0)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test07()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #7: size returns correct value after adds and removeBack ";
  LinkList.addBack(21);
  LinkList.removeBack();
  if(LinkList.getLength() == 0)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test08()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #8: size reduced by 1 removeFront on populated list ";
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.removeFront();
  if(LinkList.getLength() == 8)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test09()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #9: size reduced by 1 removeBack on populated list ";
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.removeBack();
  if(LinkList.getLength() == 8)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test10()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #10: positionOf returns 0 on empty list ";
  if (LinkList.positionOf(10) == 0)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test11()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #11: positionOf returns 0 when value not in list ";
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  if (LinkList.positionOf(15) == 0)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test12()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #12: positionOf returns correct index if value is in populated list ";
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(4);
  LinkList.addFront(1);
  LinkList.addFront(6);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  if ((LinkList.positionOf(6) == 4) || (LinkList.positionOf(4) == 6))
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test13()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #13: removeFront on empty list returns false ";
  if( LinkList.removeFront() == false)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test14()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #14: removeBack on empty list returns false ";
  if( LinkList.removeBack() == false)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test15()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #15: insert returns false given an invalid position ";
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  if(LinkList.insert(15, 15) == false)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}

void LinkedListTester::test16()
{
  LinkedList<int> LinkList;
  std::cout<<"Test #16: order preserved by insert on populated list ";
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.addFront(1);
  LinkList.insert(5,21);
  if(LinkList.getLength() == 10)
  {
    std::cout<<"PASSED!\n";
  }
  else
  {
    std::cout<<"FAILED!\n";
  }
}
