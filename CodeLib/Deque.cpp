#include "ADT.h"
#include "Deque.h"

Deque::Element::Element(int value = 0, Element* ptrNext = nullptr, Element* ptrPrev = nullptr)
{
    this->value = value;
    next = ptrNext;
    prev = ptrPrev;
}

Deque::Deque()
{
    head = nullptr;
    tail = nullptr;
}

Deque::~Deque()
{
    clear();
}

Deque::Deque(Deque &old)
{
    Element* current = new Element;
    current = old.head;
    while (current != nullptr)
    {
        pushFront(current->value);
        current = current->next;
    }
}

void Deque::pushFront(int val)
{
    Element* newEl = new Element;
    newEl->value = val;
    newEl->next = nullptr;
    if (head != nullptr)
    {
        newEl->prev = tail;
        tail->next = newEl;
        tail = newEl;
        Size++;
    }
    else
    {
        newEl->prev = nullptr;
        head = tail = newEl;
        Size = 1;
    }
}

void Deque::pushBack(int val)
{
    Element* newEl = new Element;
    newEl->value = val;
    if (head != nullptr)
    {
        newEl->next = head;
        head->prev = newEl;
        head = newEl;
        Size++;
    }
    else
    {
        newEl->next = nullptr;
        head = tail = newEl;
        Size = 1;
    }
}

int Deque::popFront()
{
    if (head != nullptr)
    {
        if (head != tail)
        {
            Element* current = tail;
            int val = tail->value;
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
            Size--;
            return val;
        }
        else if (head == tail)
        {
            int val = head->value;
            delete head;
            tail = nullptr;
            head = nullptr;
            return val;
        }
    }
    else
    {
        //mistake
    }
}


int Deque::popBack()
{
    if (head != nullptr)
    {
        int val = head->value;
        Element* current = head;
        head = head->next;
        delete current;
        Size--;
        return val;
    }
    else
    {
        //mistake
    }
}

int Deque::size()
{
    return Size;
}


void Deque::clear()
{
    while (head != nullptr)
    {
        tail = head;
        head = head->next;
        delete tail;
        tail = head;
        Size = 0;
    }
}

int Deque::getFront()
{
    if (tail != nullptr)
    {
        return tail->value;
    }
    else
    {
        //mistake
    }
}

int Deque::getBack()
{
    if (head != nullptr)
    {
        return head->value;
    }
    else
    {
        //mistake
    }
}

bool Deque::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Deque::toString()
{
    std::string line = "";
    Element* newEl = new Element;
    newEl = head;
    if (head == nullptr)
    {
        return "Empty";
    }
    while (newEl != nullptr)
    {
        line.append(std::to_string(newEl->value) + " ");
        newEl = newEl->next;
    }
    return std::string(line);
}

/*void Deque::reverse()
{
    if (head != nullptr)
    {
        Deque Deq;
        Element* newEl = new Element;
        newEl = head;
        while (newEl != nullptr)
        {
            Deq.pushBack(newEl->value);
            newEl = newEl->next;
        }
        clear();
        while (!Deq.isEmpty())
        {
            pushFront(Deq.popBack());
        }
    }
    else
    {
        //mistake
    }
}
*/