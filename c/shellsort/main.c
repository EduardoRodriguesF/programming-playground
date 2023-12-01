#include <stdio.h>

void shellsort(int v[], int n);
void print_array(int v[], int n);

int main() {
    int n = 6;
    int arr[] = { 2, 67, 31, 3, 5, 10 };

    shellsort(arr, n);

    print_array(arr, n);
    return 0;
}

void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

void print_array(int v[], int n) {
    printf("[ ");

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }

    printf(" ]\n");
}
