#include <iostream>

using namespace std;

void printAsc(int start, int end) {
  cout << start << endl;

  if (start != end) {
    printAsc(start+1, end);
  }
}

int main() {
  printAsc(5, 10);

  return 0;
}
