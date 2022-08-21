#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int val) {
  int low, high, mid;
  int index = -1;
  bool found = false;

  low = 0;
  high = size - 1;

  while (!found) {
    mid = (low + high) / 2;

    if (arr[mid] == val) {
      index = mid;
      found = true;
    } else if (val < arr[mid]) 
      high = mid - 1;
    else low = mid + 1;
  }

  return index;
}

int main() {
  int arr[9] = {0, 1, 5, 7, 8, 9, 10, 12, 14};

  cout << binarySearch(arr, 9, 10) << endl;

  return 0;
}
