#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int arr[], int start, int end, int key) {
    if (start > end) {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
        return true;
    }

    if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, end, key);
    } else {
        return binarySearch(arr, start, mid - 1, key);
    }
}

int main() {
    int size, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements (sorted order):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    bool ans = binarySearch(arr, 0, size - 1, key);

    if (ans) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    return 0;
}
