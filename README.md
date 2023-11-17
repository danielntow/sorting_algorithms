# Sorting Algorithms in C

This repository contains implementations of various sorting algorithms in C.

## Algorithms Included:

- **Bubble Sort:** Simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


- **Selection Sort:** Divides the array into a sorted and an unsorted region, selecting the minimum element from the unsorted region in each pass.

- **Insertion Sort:** Builds the final sorted array one item at a time, comparing each element with the elements in the sorted part of the array and shifting elements as needed.

- **Merge Sort:** A divide-and-conquer algorithm that divides the array into two halves, sorts each half, and then merges the sorted halves to produce a fully sorted array.

- **Quick Sort:** Uses a divide-and-conquer strategy to partition the array into smaller subarrays, sorting those subarrays independently.

## How to Use:

- Each sorting algorithm has its own C file with a clear implementation.
- Compile the respective C file using a C compiler (e.g., gcc) to generate the executable.
- Run the generated executable to see the sorting algorithm in action.

`happy coding`

