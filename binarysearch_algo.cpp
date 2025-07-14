int binarySearchRec(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;  // key not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRec(arr, mid + 1, high, key);
    else
        return binarySearchRec(arr, low, mid - 1, key);
}


/*
Worst case Scenerio
| Version   | Time Complexity | Space Complexity               |
| --------- | --------------- | ------------------------------ |
| Iterative | `O(log n)`      | `O(1)`                         |
| Recursive | `O(log n)`      | `O(log n)` (due to call stack) |

*/