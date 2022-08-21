#include <iostream>

using namespace std;

void resizeArray(int*& arr, int currentSize, int newSize) {
  int *result = new int[newSize];

  for (int i = 0; i < currentSize; i++) 
    result[i] = arr[i];

  delete[] arr;
  arr = result;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i];
  }
}

int main() {
  int size = 10;
  int *arr = new int[size];

  for (int i = 0; i < size; i++)
    arr[i] = i * 10;

  printArray(arr, size);
  
  int oneMore = 110;
  int newSize = size * 2;

  resizeArray(arr, size, newSize);
  size = newSize;

  arr[size++] = oneMore;
  
  cout << "New one!\n";
  printArray(arr, size);
}
