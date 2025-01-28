#include <stdio.h>

int searchTwoPointers(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        if (arr[left] == target) {
            return left;
        }
        if (arr[right] == target) {
            return right;
        }
        left++;
        right--;
    }
    return -1;
}

int main() {
    int size, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = searchTwoPointers(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
