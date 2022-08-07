#include <iostream>
using namespace std;

int main() {
  char input;
  int ascii_value;

  cout << "Please enter a character:" << endl;
  cin >> input;

  ascii_value = (int) input;

  cout << "The ASCII value of " << input << " is " << ascii_value << endl;

  return 0;
}
