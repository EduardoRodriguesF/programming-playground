#include <iostream>
using namespace std;

int main() {
  const int WEEK_DAYS = 7;
  int traveled_days;

  cout << "Please enter the number of days you traveled:" << endl;
  cin >> traveled_days;

  int full_weeks = traveled_days / WEEK_DAYS;
  int additional_days = traveled_days % WEEK_DAYS;

  if (full_weeks == 0) {
    cout << "You've traveled only for " << additional_days << " days!";
    return 1;
  }

  if (additional_days == 0) {
    cout << "You've traveled for exactly " << full_weeks << " weeks";
    return 0;
  } 

  cout << "You've traveled for " << full_weeks << " weeks and " << additional_days << " additional days.";
  return 0;
}
