#include <iostream>
#include <vector>

using namespace std;
/* In a merge sort you break down the eliments of an array into
sub arrays until you only have one eliment in each sub array.
then you combine adjacent arrays into bigger arrays and sort them
you continue this process until the array is properly sorted*/

void test_rec(int &i);
void test_arr(int arr, int arr1[], int arr2[]);
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

    size /= 2;
    cout << "\nsize: " << size << endl;

    int *arr1 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr[i];
    }

    int *arr2 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[size + i];
    }

    // test arrays to see if populated
    test_arr(size, arr1, arr2);

    if (size != 1)
    {
        //cout << "\nmakes here1: " << endl;
        merge_func(arr1, size);
    }
    if (size != 1)
    {
        //cout << "\nmakes here2: " << endl;
        merge_func(arr2, size);
    }
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

void test_arr(int half_size, int arr1[], int arr2[]){
    // test arrays to see if populated
    for (int i = 0; i < half_size; i++)
    {
        cout << arr1[i] << ", ";
    }
    //delete arr1;

    cout << endl;
    cout << endl;

    for (int i = 0; i < half_size; i++)
    {
        cout << arr2[i] << ", ";
    }
    //delete arr2;

    return;
    ////////////////////////////////////
}