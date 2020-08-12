/*
    Student Name:   Maria Azam
    Student ID:     200402217
    Date:           Tuesday, August 11, 2020

    Purpose:        Sort an array of user-input size and integers using the heapSort algorithm.
    References:     The addition of 'largest' in 'heapify' was added after using this resource: https://www.geeksforgeeks.org/heap-sort/
*/

#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void heapify(int array[], int size, int root)
{
    //Determine left and right children of current node
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    //Root of sub-tree should be largest node
    int largest = root;

    //Find largest child of current node
    //'left < n' & 'right < n' ensure no out-of-bound error
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    
    //If largest element was not root,
    if (largest != root)
    {
        //Swap with root of current sub-tree
        swap(array[root], array[largest]);

        //Heapify sub-tree of largest child
        heapify(array, size, largest);

    }
}

void heapSort(int array[], int size)
{
    //Heapfiy array, beginning with first non-leaf node
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
    
    for (int i = size - 1; i > 0; i--)
    {
        //Pop max element & insert into end of heap
        swap(array[0], array[i]);
        
        //Heapify remaining unsorted portion of array to maintain max-heap structure
        heapify(array, i, 0);
    }
}

int main()
{
    int N;

    cout << "How many items would you like to sort? ";
    cin >> N;

    int array[N];

    cout << "Enter the items to be sorted: ";
    for (int i = 0; i < N; i++)
        cin >> array[i];

    heapSort(array, N);

    cout << "The sorted array is: ";
    printArray(array, N);

    return  0;
}