#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 20

using namespace std;

template <typename T>
class stack
{
    public:
        stack()
        {
            size = 0;
        }
        
        void push(T val)
        {
            if (size == MAX_SIZE)
            {
                throw overflow_error("Called push on full stack.");
            }
            
            else
            {
                size++;
                data[size] = val;
            }
        }
        
        void pop()
        {
            if (size == 0)
            {
                throw out_of_range("Called pop on empty stack.");
            }
            
            else
            {
                size--;
            }
        }
        
        void pop_two()
        {
            if (size == 1)
            {
                throw out_of_range("Called pop_two on a stack of size 1.");
            }

            else if (size == 0)
            {
                throw out_of_range("Called pop_two on empty stack.");
            }
            
            else
            {
                size--;
                size--;
            }
        }
        
        T top()
        {
            if (size == 0)
            {
                throw underflow_error("Called top on empty stack.");
            }
            
            else
            {
                return data[size];
            }
        }
        
        bool empty()
        {
            if (size == 0)
            {
                return true;
            }
            
            else
            {
                return false;
            }
        }
        
    private:
        T data[MAX_SIZE];
        int size;
};

#endif