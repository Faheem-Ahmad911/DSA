#include <iostream>
using namespace std;
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int ind = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            ind++;
            swap(arr[ind], arr[j]);
        }
    }
    swap(arr[ind + 1], arr[high]);
    return ind + 1;
}

void QuicK_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(arr, low, high);
        QuicK_Sort(arr, low, pivot - 1);
        QuicK_Sort(arr, pivot + 1, high);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuicK_Sort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}