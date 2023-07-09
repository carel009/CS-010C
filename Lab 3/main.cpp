#include <iostream>
#include <stdexcept>
#include <vector>
#include <ctime>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    int vectorSize = vals.size();
    int minimumIndex = index;
    
    for (int i = (index + 1); i < vectorSize; i++)
    {
        if (vals[i] < vals[minimumIndex])
        {
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

template <typename T>
void selection_sort(vector<T> &vals)
{
    int vectorSize = vals.size();
    
    for ( int i = 0; i < (vectorSize - 1); i++)
    {
        int minimumIndex = min_index(vals, i);
        T temp = vals[i];
        vals[i] = vals[minimumIndex];
        vals[minimumIndex] = temp;
    }
}

template <typename T>
T getElement(vector<T> vals, int index)
{
    return vals.at(index);
}

vector<char> createVector()
{
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main()
{
    srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     
     while (--numOfRuns >= 0)
     {
         cout << "Enter a number: " << endl;
         cin >> index;
         try
         {
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
         }
         catch(out_of_range& excpt)
         {
            cout << "Out of range exception occured" << endl;
         }
    }
    
    // Selection Sort Check 
        /*cout << "Select a data type: c(character) or d(double) or i(integer) or s(string)" << endl;
        char selection;
        cin >> selection;
        cin.ignore();
        
        if(selection == 'c')
        {
            cout << "select the vector size" << endl;
            int amount;
            cin >> amount;
            cin.ignore();
            cout << "Enter " << amount << " char(s)" << endl;
            vector<char> c;
            
            for(int i = 0; i < amount; i++)
            {
                char chr;
                cin >> chr;
                cin.ignore();
                c.push_back(chr);
            }
            
            selection_sort(c);
            cout << "Selection sort: ";
            
            for(int i = 0; i < amount; i++)
            {
                cout << c[i] << " ";
            }
        }
        
        else if(selection == 'd')
        {
            cout << "select the vector size" << endl;
            int amount;
            cin >> amount;
            cin.ignore();
            cout << "Enter " << amount << " double(s)" << endl;
            vector<double> d;
                        
            for(int i = 0; i < amount; i++)
            {
                double dub;
                cin >> dub;
                cin.ignore();
                d.push_back(dub);
            }
            
            selection_sort(d);
            cout << "Selection sort: ";
            
            for(int i = 0; i < amount; i++)
            {
                cout << d[i] << " ";
            }
        }
        
        else if(selection == 'i')
        {
            cout << "select the vector size" << endl;
            int amount;
            cin >> amount;
            cin.ignore();
            cout << "Enter " << amount << " int(s)" << endl;
            vector<int> intg;
                        
            for(int i = 0; i < amount; i++)
            {
                int intgr;
                cin >> intgr;
                cin.ignore();
                intg.push_back(intgr);
            }
            
            selection_sort(intg);
            cout << "Selection sort: ";
            
            for(int i = 0; i < amount; i++)
            {
                cout << intg[i] << " ";
            }
        }
        
        else if(selection == 's')
        {
            cout << "select the vector size" << endl;
            int amount;
            cin >> amount;
            cin.ignore();
            cout << "Enter " << amount << " string(s)" << endl;
            vector<string> s;
                        
            for(int i = 0; i < amount; i++)
            {
                string str;
                cin >> str;
                cin.ignore();
                s.push_back(str);
            }
            
            selection_sort(s);
            cout << "Selection sort: ";
            
            for(int i = 0; i < amount; i++)
            {
                cout << s[i] << " ";
            }
        }
        
        else
        {
            cout << "Invalid input" << endl;
        }*/
    
    return 0;
}