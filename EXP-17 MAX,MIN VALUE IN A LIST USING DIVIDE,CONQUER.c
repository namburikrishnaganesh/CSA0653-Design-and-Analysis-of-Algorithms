#include <stdio.h>
#include <limits.h>
void findMinMax(int arr[], int left, int right, int *min, int *max) {
    if (left == right) {
        if (*min > arr[left]) {
            *min = arr[left];
        }
        if (*max < arr[left]) {
            *max = arr[left];
        }
        return;
    }
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            if (*min > arr[left]) {
                *min = arr[left];
            }
            if (*max < arr[right]) {
                *max = arr[right];
            }
        } else {
            if (*min > arr[right]) {
                *min = arr[right];
            }
            if (*max < arr[left]) {
                *max = arr[left];
            }
        }
        return;
    }
    int mid = left + (right - left) / 2;
    findMinMax(arr, left, mid, min, max);
    findMinMax(arr, mid + 1, right, min, max);
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 3, 15, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = INT_MAX, max = INT_MIN;
    findMinMax(arr, 0, n - 1, &min, &max);
    printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);
    return 0;
}