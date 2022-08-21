#include <iostream>

using namespace std;

bool areAllEven(int arr[], int n) {
  if (n == 1) {
    return (arr[0] % 2 == 0);
  }

  bool result = areAllEven(arr, n - 1);
  
  if (result) {
    return (arr[n - 1] % 2 == 0);
  }

  return false;
}

int main() {
  int arr[4] = {2, 20, 54};

  cout << areAllEven(arr, 4);

  return 0;
}
