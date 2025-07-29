#include<iostream>
using namespace std;

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
      int n1 = mid - left + 1;
      int n2 = right - mid;

      // Create temp arrays
      int* L = new int[n1];
      int* R = new int[n2];

      // Copy data to temp arrays
      for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
      for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

      // Merge the temp arrays back into arr[left..right]
      int i = 0, j = 0, k = left;
      while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                  arr[k++] = L[i++];
            } else {
                  arr[k++] = R[j++];
            }
      }

      // Copy the remaining elements
      while (i < n1)
            arr[k++] = L[i++];
      while (j < n2)
            arr[k++] = R[j++];

      delete[] L;
      delete[] R;
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
      if (left < right) {
            int mid = left + (right - left) / 2;

            // Sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
      }
}

int main() {
      int n;
      cout << "Enter number of elements: ";
      cin >> n;
      int* arr = new int[n];
      cout << "Enter elements:\n";
      for (int i = 0; i < n; i++)
            cin >> arr[i];

      mergeSort(arr, 0, n - 1);

      cout << "Sorted array:\n";
      for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
      cout << endl;

      delete[] arr;
      return 0;
}