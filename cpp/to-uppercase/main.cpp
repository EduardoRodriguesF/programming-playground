#include <iostream>
using namespace std;

// ASCII of 'a' minus ASCII of 'A'
const int CAPITALIZATION_ASCII_OFFSET = 'a' - 'A';

char to_uppercase(char input) {
  return input - CAPITALIZATION_ASCII_OFFSET;
}

int main() {
  char input;
  char result;

  cout << "Please enter a lowercased character:\n";
  cin >> input;

  result = to_uppercase(input);

  cout << "Uppercased '" << input << "' is '" << result << "'\n";

  return 0;
}
