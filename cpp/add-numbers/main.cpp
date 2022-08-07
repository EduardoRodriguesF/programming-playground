#include <iostream>
using namespace std;

int main() {
  int num1;
  int num2;
  int sum;

  cout<<"Please enter two numbers separated by a space:"<<endl;
  cin>>num1>>num2; // Separate cin>>num2 line works the same

  sum = num1 + num2;

  cout<<num1<<" + "<<num2<<" = "<<sum<<endl;

  return 0;
}
