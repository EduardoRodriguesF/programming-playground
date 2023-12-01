#include <stdio.h>
#include <time.h>

int binsearch_v1(int x, int v[], int n);
int binsearch_v2(int x, int v[], int n);

int main() {
    size_t n = 1000000;
    int arr[n];
    for (size_t i = 0; i < n; i++) arr[i] = i+1;

    clock_t begin = clock();

    int index = binsearch_v2(211, arr, n);

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Found: %d\n", index);
    printf("Took %f\n", time_spent);

    return 0;
}

int binsearch_v1(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid]) high = mid + 1;
        else if (x > v[mid]) low = mid + 1;
        else return mid;
    }

    return -1;
}

int binsearch_v2(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high) {
        if (x < v[mid]) high = mid - 1;
        else low = mid + 1;

        mid = (low + high) / 2;
    }

    if (x == v[mid]) return mid;

    return -1;
}
