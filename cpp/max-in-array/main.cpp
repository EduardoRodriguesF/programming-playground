#include <iostream>
using namespace std;

int max(int a, int b); 
int max_in_array(int arr[], int size);

int main() {
  int arr[5] = {1, 6, 4, 3, 9};

  cout << max_in_array(arr, 5);

  return 0;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int max_in_array(int arr[], int size) {
  if (size == 1) {
    return arr[0];
  }

  if (size == 2) {
    return max(arr[0], arr[1]);
  }

  int current_max = arr[0];

  for (int i = 1; i < size; i++) {
    current_max = max(current_max, arr[i]);
  }

  return current_max;
}
