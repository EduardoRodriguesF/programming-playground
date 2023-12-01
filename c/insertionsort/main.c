#include <stddef.h>
#include <stdio.h>

void insertionsort(int arr[], size_t n);

int main() {
    int arr[] = {3, 2, 5, 1, 2, 6, 10, 3};

    insertionsort(arr, 8);

    for (int i = 0; i < 8; i++) printf("%d ", arr[i]);

    return 0;
}

void insertionsort(int arr[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element = arr[i];

        for (int j = i - 1; j >= 0; j--) {
            if (element < arr[j]) {
                arr[j+1] = arr[j];
                arr[j] = element;
                continue;
            }

            break;
        }
    }
}
