#include "IntList.h"
using namespace std;

IntList::IntList()
{
    dummyHead = 0;
    dummyTail = 0;
}

void IntList::push_front(int value)
{
    if (dummyHead == 0)
    {
        dummyHead = new IntNode(value);
        dummyTail = dummyHead;
    }
    
    else
    {
        IntNode* newNode = new IntNode(value);
        dummyHead->prev = newNode;
        newNode->next = dummyHead;
        dummyHead = newNode;
    }
}

void IntList:: pop_front()
{
    if (dummyHead == 0)
    {
        return;
    }
    
    if (dummyHead == dummyTail)
    {
        delete dummyHead;
        dummyHead = dummyTail = 0;
        return;
    }
    
    else
    {
        IntNode* temp = dummyHead;
        dummyHead = dummyHead->next;
        dummyHead->prev = 0;
        delete temp;
    }
}

void IntList::push_back(int value)
{
    if (dummyHead == 0)
    {
        dummyHead = new IntNode(value);
        dummyTail = dummyHead;
    }
    
    else
    {
        IntNode* newNode = new IntNode(value);
        dummyTail->next = newNode;
        newNode->prev = dummyTail;
        dummyTail = newNode;
    }
}

void IntList:: pop_back()
{
    if (dummyHead == 0)
    {
        return;
    }
    
    if (dummyHead == dummyTail)
    {
        delete dummyHead;
        dummyHead = dummyTail = 0;
        return;
    }
    
    else
    {
        IntNode* temp = dummyTail;
        dummyTail = dummyTail->prev;
        dummyTail->next = 0;
        delete temp;
    }
}

bool IntList::empty() const
{
    if (dummyHead == 0)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

ostream & operator << (ostream &out, const IntList &rhs)
{
    IntNode* ptr = rhs.dummyHead;
    while (ptr != 0)
    {
        out << ptr->data;
        ptr = ptr->next;
        if (ptr != 0)
        {
            out << " ";
        }
    }
    return out;
}

void IntList::printReverse() const
{
    IntNode* ptr = dummyTail;
    while (ptr != 0)
    {
        cout << " " << ptr->data;
        ptr = ptr->prev;
    }
}

IntList::~IntList()
{
    while (!empty())
    {
        pop_back();
    }
}