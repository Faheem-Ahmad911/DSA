def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        # Move elements greater than key to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Example usage
arr2 = [8, 4, 1, 5, 2]
print("Original (Insertion):", arr2)
insertion_sort(arr2)
print("Sorted (Insertion):  ", arr2)
