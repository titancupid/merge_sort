#include <iostream>
#include <vector>

using namespace std;
/* In a merge sort you break down the eliments of an array into
sub arrays until you only have one eliment in each sub array.
then you combine adjacent arrays into bigger arrays and sort them
you continue this process until the array is properly sorted*/

int merge_func(vector<int> arr);
void test_rec(int &i);

int main()
{
    int arr[] = {4, 18, 3, 94, 12, 8, 69, 14, 5, 1};
    
    int num = 0;
    test_rec(num);
}

int merge_func(vector<int> arr)
{
    int size = sizeof(arr);
    int *subarr = new int[size];
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