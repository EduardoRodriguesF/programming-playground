#include <iostream>
using namespace std;

int main() {
  const int WEEK_DAYS = 7;
  int traveled_days;

  cout << "Please enter the number of days you traveled:" << endl;
  cin >> traveled_days;

  int full_weeks = traveled_days / WEEK_DAYS;
  int additional_days = traveled_days % WEEK_DAYS;

  cout << "You've traveled for " << full_weeks << " weeks and " << additional_days << " additional days.";
}
