#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    const int SIZE = 20000;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
        arr[i] = i;

    int key = 19999; 

    auto start1 = high_resolution_clock::now();
    int result1 = binarySearchIterative(arr, SIZE, key);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();

    auto start2 = high_resolution_clock::now();
    int result2 = binarySearchRecursive(arr, 0, SIZE - 1, key);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();

    cout << "Iterative Result: " << result1 << ", Time: " << duration1 << " ns" << endl;
    cout << "Recursive Result: " << result2 << ", Time: " << duration2 << " ns" << endl;

    return 0;
}
