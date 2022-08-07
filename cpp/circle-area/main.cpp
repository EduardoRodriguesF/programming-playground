#include <iostream>
#include <cmath>
using namespace std;

int main() {
  const double PI = atan(1) * 4;
  double area, radius;

  cout << "Please enter the radius of the circle:" << endl; 
  cin >> radius;

  area = PI * pow(radius, 2);

  cout << "The area of the circle is " << area;

  return 0;
}
