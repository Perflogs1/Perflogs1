#include <stdio.h>

int main() {
    int n, i, j, first = -1, second = -1;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            first = i;
            break;
        }
    }
    for (i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            second = i;
            break;
        }
    }
    if (first == -1 || second == -1) {
        printf("Array is already sorted.\n");
    } else {
        printf("Swapped elements: %d and %d\n", arr[first], arr[second]);
        printf("Positions: %d and %d\n", first, second);
    }
    return 0;
}