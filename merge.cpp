#include <iostream>
#include <vector>

using namespace std;
/* In a merge sort you break down the eliments of an array into
sub arrays until you only have one eliment in each sub array.
then you combine adjacent arrays into bigger arrays and sort them
you continue this process until the array is properly sorted*/

void test_rec(int &i);
void test_arr(int size1, int size2, int arr1[], int arr2[]);
void test_merged(int merged[], int newsize);
int* split_func(int arr[], int &size);
int* merge_func(int arr1[], int arr2[], int size1, int size2);

int main()
{
    // int num = 0;
    // test_rec(num);

    int arr[] = {4, 18, 3, 94, 12, 8, 69, 14, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int* sorted = split_func(arr, size); 

    for(int i = 0; i < size; i++){
        cout << sorted[i] << ", ";
    }
    delete sorted;
}

int* split_func(int arr[], int &size)
{
    /*1) create two arrays of half the size and repeat until
        there is one eliment in each array that
      2) combine the arrays so there are two eliments in each
        of the arrays
      3) sort these sub arrays then repeat step two until the
        array is fully sorted*/

    int size1, size2;

    if (size % 2 == 1){
        size1 = size / 2;
        size2 = (size / 2) + 1;
    }
    else{
        size1 = size / 2;
        size2 = size / 2;
    }

    //cout << "\nsize1: " << size1 << endl;
    //cout << "\nsize2: " << size2 << endl;

    int *arr1 = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[i];
    }

    int *arr2 = new int[size2];
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[size1 + i];
    }

    // test arrays to see if populated
    //test_arr(size1, size2, arr1, arr2);

    if (size1 != 1)
        arr1 = split_func(arr1, size1);

    if (size2 != 1)
        arr2 = split_func(arr2, size2);


    int* sorted =  merge_func(arr1, arr2, size1, size2); // merge call

    delete arr1;
    delete arr2;

    return sorted;
}

int* merge_func(int arr1[], int arr2[], int size1, int size2)
{
    /*1) take the two arrays input and combine them to one array
      2) sort these arrays then repeat until one input array is
        empty*/

    int newsize = size1 + size2;
    int *merged = new int[newsize];

    /*Need to fill the new merged array with the contents of both
        arr1 and arr2 and sort as the arrays are being merged */

    /*need to sort as we merge so when we are adding an eliment 
    to the merged array we need to check if it is smaller than 
    the eliments already in the array so we know where to 
    insert it*/

    int i = 0, j = 0, k = 0;
    // i is the index of the merged array
    // j is the index of the array 1
    // k is the index of the array 2

    while (j < size1 && k < size2)
    {
        if (arr1[j] < arr2[k])
        {
            merged[i] = arr1[j];
            i++;
            j++;
        }
        else
        {
            merged[i] = arr2[k];
            i++;
            k++;
        }
    }

    //copy remaining eliments
    while (j < size1)
    {
        merged[i] = arr1[j];
        i++;
        j++;
    }

    while (k < size2)
    {
        merged[i] = arr2[k];
        i++;
        k++;
    }

    //test_merged(merged, newsize);
    return merged;
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

void test_arr(int size1, int size2, int arr1[], int arr2[]){
    // test arrays to see if populated
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << ", ";
    }
    //delete arr1;

    cout << endl;
    cout << endl;

    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i] << ", ";
    }

    return;
    ////////////////////////////////////
}

void test_merged(int merged[], int newsize){
    for(int i = 0; i < newsize; i++)
        cout << merged[i] << ", ";

    cout << endl;
}