/*
    Student Name:   Maria Azam
    Student ID:     200402217
    Date:           Tuesday, August 11, 2020
*/

#include <iostream>
using namespace std;

void printArray(int array[])
{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int N;

    cout << "How many items would you like to sort? ";
    cin >> N;

    int array[N];

    cout << endl << "Enter the items to be sorted: ";
    for (int i = 0; i < N; i++)
        cin >> array[i];

    printArray(array);

    return  0;
}