#include <iostream>
using namespace std;
int func_max(int nums[], int i, int j)
{
    return (nums[i] - 1) * (nums[j] - 1);
}
int main()
{
    int i, j;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Enter index i" << endl;

    cin >> i;
    cout<<"Enter index j"<<endl;
    cin >> j;
    int max = func_max(arr, i, j);
    cout << "The max element is " << max << endl;
}