#include <iostream>

using namespace std;

int factorial(int n) {
  if (n == 1) return 1;
  
  int result = factorial(n-1);
  result *= n;
  return result;
}

int main() {
  cout << factorial(5);
  return 0;
}
