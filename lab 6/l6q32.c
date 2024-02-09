#include <stdio.h>

int merge(int arr[], int low, int mid, int high, int* loop_count) {
    int temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    int inv_count = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            // Count inversions
            inv_count += mid - i + 1;
        }
        (*loop_count)++; // Increment loop count
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return inv_count;
}

int mergeSort(int arr[], int low, int high, int* loop_count) {
    int inv_count = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        inv_count += mergeSort(arr, low, mid, loop_count);
        inv_count += mergeSort(arr, mid + 1, high, loop_count);
        inv_count += merge(arr, low, mid, high, loop_count);
    }
    return inv_count;
}

int main() {
    int arr[100], arr_size, loop_count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &arr_size);

    printf("Enter the elements: ");
    for (int i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int inversions = mergeSort(arr, 0, arr_size - 1, &loop_count);

    printf("\nSorted array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Number of inversions: %d\n", inversions);
    printf("Number of loop runs: %d\n", loop_count);

    return 0;
}
