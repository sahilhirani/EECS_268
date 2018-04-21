/**
*	@file LinkedListTester.h
*	@author Sahil Hirani
*	@date 02/09/2017
*	@brief A header file for LinkedListTester class
*/
#ifndef LINKEDLISTTESTER_H
#define LINKEDLISTTESTER_H
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
class LinkedListTester
{
    public:
      /** @pre None.
    	*   @post None
    	*   @return None
    	*/
    LinkedListTester();

    
    /** @pre None.
  	*   @post Runs Tests on LinkedList
  	*   @return None
  	*/
    void runTests();

    private:
    /**
    * @brief Creates an empty list and verifies isEmpty() returns true
    **/
    void test01();

    /**
    * @brief Creates an empty list adds 1 value, verifies isEmpty() returns false
    **/
    void test02();

    /**
    * @brief Creates an empty list and runs addBack and returns correct size
    **/
    void test03();
    /**
    * @brief Creates an empty list adds multiple addFront values and verifies getLength() returns correct size
    **/
    void test04();
    /**
    * @brief Creates an empty list adds multiple addBack values and verifies getLength() returns correct size
    **/
    void test05();
    /**
    * @brief Creates an empty list and verifies getLength() returns 0 after addFront and removeFront
    **/
    void test06();
    /**
    * @brief Creates an empty list and verifies getLength() returns 0 after addBack and removeBack
    **/
    void test07();
    /**
    * @brief Creates a populated list and removes a Node then removeFront is called this test is to check to make sure that the correct size is returned
    **/
    void test08();
    /**
    * @brief Creates a populated list and removes a Node then removeBack is called this test is to check to make sure that the correct size is returned
    **/
    void test09();
    /**
    * @brief Creates an empty list and verifies positionOf() returns 0
    **/
    void test10();
    /**
    * @brief Creates an empty list and verifies positionOf() returns 0 when the value is not in the list
    **/
    void test11();
    /**
    * @brief Creates an empty list and verifies positionOf() returns correct index value of populated list
    **/
    void test12();
    /**
    * @brief Creates an empty list and verifies removeFront() returns false
    **/
    void test13();
    /**
    * @brief Creates an empty list and verifies removeBack() returns false
    **/
    void test14();
    /**
    * @brief Creates a populated list and verifies that insert returns false given an invalid position
    **/
    void test15();
    /**
    * @brief Creates a populated list and verifies that getLength() returns correct length after insert()
    **/
    void test16();


};
#endif
