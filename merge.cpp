#include <iostream>
#include <vector>

using namespace std;
/* In a merge sort you break down the eliments of an array into
sub arrays until you only have one eliment in each sub array.
then you combine adjacent arrays into bigger arrays and sort them
you continue this process until the array is properly sorted*/

void test_rec(int &i);
int merge_func(int arr[], int &size);

int main()
{
    // int num = 0;
    // test_rec(num);

    int arr[] = {4, 18, 3, 94, 12, 8, 69, 14, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_func(arr, size); 
}

int merge_func(int arr[], int &size)
{
    /*1) create two arrays of half the size and repeat until 
        there is one eliment in each array that
      2) combine the arrays so there are two eliments in each 
        of the arrays 
      3) sort these sub arrays then repeat step two until the
        array is fully sorted*/
    if (size % 2 == 1)
        size += 1;

    int half_size = size / 2;
    // cout << "size: " << size << endl;
    // cout << "half size: " << half_size << endl;
    int* arr1 = new int[half_size];
    for(int i = 0; i < half_size; i++){
        arr1[i] = arr[i];
    }

    int* arr2 = new int[half_size];
    for(int i = 0; i < half_size; i++){
        arr2[i] = arr[half_size+i];
    }
    
    //test arrays to see if populated
    for(int i = 0; i < half_size; i++){
        cout << arr1[i] << ", ";
    }
    delete arr1;

    cout << endl;
    cout << endl;

    for(int i = 0; i < half_size; i++){
        cout << arr2[i] << ", ";
    }
    delete arr2;

    return 0;
    ////////////////////////////////////
}

void test_rec(int &i)
{
    i += 1;
    cout << i << endl;
    if (i == 10)
    {
        cout << i << endl; 
        return;
    }
    test_rec(i);
}