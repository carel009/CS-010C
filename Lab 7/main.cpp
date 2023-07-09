#include <iostream>
#include <ctime>
using namespace std;

const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int Partition_Midpoint(int numbers[], int i, int k)
{
    int midpoint = i + (k-i)/2;
    int pivot = numbers[midpoint];
    
    bool done = false;
    while (!done)
    {
        while (numbers[i] < pivot)
        {
            i++;
        }
        
        while (pivot < numbers[k])
        {
            k--;
        }
        
        if (i >= k)
        {
            done = true;
        }
        
        else
        {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            i++;
            k--;
        }
    }
    return k;
}

int middle(int a, int b, int c)
{
    int median;
    
    if (a > min(b, c) && a < max(b, c))
    {
        median = a;
    }
    
    if (b > min(a, c) && b < max(a, c))
    {
        median = b;
    }
    
    if (c > min(a, b) && c < max(a, b))
    {
        median = c;
    }
    
    return median;
}

int Partition_MedianOfThree(int numbers[], int i, int k)
{
    int midpoint = i + (k-i)/2;
    int pivot = middle(numbers[i], numbers[midpoint], numbers[k]);
    
    bool done = false;
    while (!done)
    {
        while (numbers[i] < pivot)
        {
            i++;
        }
        
        while (pivot < numbers[k])
        {
            k--;
        }
        
        if (i >= k)
        {
            done = true;
        }
        
        else
        {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            i++;
            k--;
        }
    }
    return k;
}

void Quicksort_Midpoint(int numbers[], int i, int k)
{
    if (i >= k)
    {
        return;
    }
    
    int j = Partition_Midpoint(numbers, i, k);
    
    Quicksort_Midpoint(numbers, i, j);
    Quicksort_Midpoint(numbers, j+1, k);
}

void Quicksort_MedianOfThree(int numbers[], int i, int k)
{
   if (i >= k)
    {
        return;
    }
    
    int j = Partition_MedianOfThree(numbers, i, k);
    
    Quicksort_Midpoint(numbers, i, j);
    Quicksort_Midpoint(numbers, j+1, k); 
}

void InsertionSort(int numbers[], int numbersSize)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    
    for (i = 1; i < numbersSize; ++i)
    {
        j = i;
        
        while (j > 0 && numbers[j] < numbers[j-1])
        {
            temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            --j;
        }
    }
}

int main()
{
    srand(time(0));
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1, arr2, arr3);
    
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    
    clock_t Start1 = clock();
    Quicksort_Midpoint(arr1, 0, NUMBERS_SIZE-1); //call sort function here
    clock_t End1 = clock();
    int elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for Quicksort_Midpoint: " << elapsedTime1 << endl;
    
    clock_t Start2 = clock();
    Quicksort_MedianOfThree(arr2, 0, NUMBERS_SIZE-1); //call sort function here
    clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for Quicksort_MedianOfThree: " << elapsedTime2 << endl;
    
    clock_t Start3 = clock();
    InsertionSort(arr3, NUMBERS_SIZE); //call sort function here
    clock_t End3 = clock();
    int elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for InsertionSort: " << elapsedTime3 << endl;
    
    cout << endl;//repeat above
    
    Start1 = clock();
    Quicksort_Midpoint(arr1, 0, NUMBERS_SIZE-1); //call sort function here
    End1 = clock();
    elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for Quicksort_Midpoint: " << elapsedTime1 << endl;
    
    Start2 = clock();
    Quicksort_MedianOfThree(arr2, 0, NUMBERS_SIZE-1); //call sort function here
    End2 = clock();
    elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for Quicksort_MedianOfThree: " << elapsedTime2 << endl;
    
    Start3 = clock();
    InsertionSort(arr3, NUMBERS_SIZE); //call sort function here
    End3 = clock();
    elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for InsertionSort: " << elapsedTime3 << endl;
    
    return 0;
}