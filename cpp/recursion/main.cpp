#include <iostream>

using namespace std;

void printAsc(int start, int end) {
  if (start == end) {
    cout << start << endl;
    return;
  }

  printAsc(start, end-1);
  cout << end << endl;
}

int main() {
  printAsc(5, 10);

  return 0;
}
