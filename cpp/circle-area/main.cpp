#include <iostream>
#include <cmath>
using namespace std;

const double PI = atan(1) * 4;

int main() {
  double area, radius;

  cout << "Please enter the radius of the circle:" << endl; 
  cin >> radius;

  area = PI * pow(radius, 2);

  cout << "The area of the circle is " << area;

  return 0;
}
