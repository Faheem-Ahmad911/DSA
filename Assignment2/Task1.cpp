#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void Bubble_Sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void Insertion_Sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int element = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > element)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }
}
void merge(int arr[], int left, int mid, int right) {
    int s1 = mid - left + 1;
    int s2 = right - mid;
    int* arr1 = new int[s1];
    int* arr2 = new int[s2];
    for (int i = 0; i < s1; i++) {
        arr1[i] = arr[left + i];
    }
    for (int j = 0; j < s2; j++) {
        arr2[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < s1 && j < s2) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < s1) {
        arr[k++] = arr1[i++];
    }
    while (j < s2) {
        arr[k++] = arr2[j++];
    }
    delete[] arr1;
    delete[] arr2;
}
void Merge_sort(int arr[],int left,int right){
    if (left<right){
        int mid =left+(right-left)/2;
        Merge_sort(arr,left,mid);
        Merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    const int n = 10000;
    int arr1[n], arr2[n], arr3[n];

    // Fill arrays with random values
    srand(0);
    for (int i = 0; i < n; ++i) {
        int val = rand();
        arr1[i] = arr2[i] = arr3[i] = val;
    }


    // Bubble Sort
    auto start = high_resolution_clock::now();
    Bubble_Sort(arr1, n);
    auto end = high_resolution_clock::now();
    auto bubble_duration = duration_cast<milliseconds>(end - start).count();
    cout << "Bubble Sort time: " << bubble_duration << " ms" << endl;

    // Insertion Sort
    start = high_resolution_clock::now();
    Insertion_Sort(arr2, n);
    end = high_resolution_clock::now();
    auto insertion_duration = duration_cast<milliseconds>(end - start).count();
    cout << "Insertion Sort time: " << insertion_duration << " ms" << endl;

    // Merge Sort
    start = high_resolution_clock::now();
    Merge_sort(arr3, 0, n - 1);
    end = high_resolution_clock::now();
    auto merge_duration = duration_cast<milliseconds>(end - start).count();
    cout << "Merge Sort time: " << merge_duration << " ms" << endl;

    return 0;
}