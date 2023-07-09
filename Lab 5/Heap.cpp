#include "Heap.h"

#include <iostream>

Heap::Heap()
{
    numItems = 0;
}

void Heap::enqueue(PrintJob* node)
{
    if (numItems < MAX_HEAP_SIZE)
    {
        int i = numItems;
        arr[numItems] = node;
        numItems++;
        
        while ((i != 0) && (arr[parentNode(i)]->getPriority() < arr[i]->getPriority()))
        {
            swap(parentNode(i), i);
            i = parentNode(i);
        }
    }
    
    else
    {
        cout << "Queue is full." << endl;
    }
}

void Heap::dequeue()
{
    if (numItems > 0)
    {
        PrintJob* node = highest();
        arr[0] = arr[numItems - 1];
        numItems--;
        delete(node);
        trickleDown(0);
    }
    
    else
    {
        cout << "Queue is empty." << endl;
    }
}

PrintJob* Heap::highest()
{
    if (numItems > 0)
    {
        return arr[0];
    }
    
    else
    {
        return NULL;
    }
}

void Heap::print()
{
    if (numItems > 0)
    {
        cout << "Priority: " << highest()->getPriority() 
        << ", Job Number: " << highest()->getJobNumber()
        << ", Number of Pages: " << highest()->getPages() << endl;
    }
    
    else
    {
        cout << "Queue is empty." << endl;
    }
}

void Heap::trickleDown(int i)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    
    if ((left < numItems) &&(arr[left]->getPriority() > arr[largest]->getPriority()))
    {
        largest = left;
    }
    
    if ((right < numItems) &&(arr[right]->getPriority() > arr[largest]->getPriority()))
    {
        largest = right;
    }
    
    if (i != largest)
    {
        swap(i, largest);
        trickleDown(largest);
    }
}

void Heap::swap(int i, int j)
{
    PrintJob* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Heap::parentNode(int i)
{
    int pNode = (i - 1)/ 2;
    return pNode;
}

int Heap::leftChild(int i)
{
    int lChild = 2 * i + 1;
    return lChild;
}

int Heap::rightChild(int i)
{
    int rChild = 2 * i + 2;
    return rChild;
}