#include <iostream>
#include "IntList.h"
using namespace std;

int main()
{
    IntList list;
    list.push_back(6);
    list.push_back(7);
    list.push_front(5);
    list.push_front(4);
    list.push_back(8);
    list.push_back(9);
    list.push_front(3);
    list.push_back(10);
    list.push_front(2);
    list.push_front(1);
    cout << "List after pushing data:" << list << endl;
    cout << "List in reverse order:"; 
    list.printReverse();
    cout << endl;
    list.pop_back();
    list.pop_back();
    list.pop_front();
    list.pop_front();
    cout << "List after poping data:" << list << endl;
    cout << "List in reverse order:";
    list.printReverse();
    cout << endl;
    if(list.empty() == false) {cout << "not empty" << endl;}
    list.~IntList();
    if(list.empty() == true) {cout << "empty" << endl;}
    return 0;
}