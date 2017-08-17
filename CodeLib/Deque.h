#pragma once

#include "ADT.h"
#include <string>
/*
* This class implements ADT interface. This means, that he must define
* and implement all methonds listed in ADT
*/
class Deque : ADT
{

public:
    Deque();
    ~Deque()override;
    Deque(Deque&);
    void push(int) override;
    void pushFront(int);
    int popBack();
    int pop() override;
    int size();
    int getBack();
    int get();
    bool isEmpty()override;
    std::string toString()override;
    void reverse();
    void clear();

protected:
    /*
    * Structure that represent a single element of Deque.
    */
    struct Element
    {
        int value = 0;
        Element* next = nullptr;
        Element* prev = nullptr;
         Element(int, Element*, Element*);
    };
    Element* head = nullptr;
    Element* tail = nullptr;
    int sizeOfDeque = 0;


};