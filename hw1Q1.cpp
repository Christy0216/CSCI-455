//Question 1
#include <iostream>
using namespace std;


double mySqrt(double s){ // eg. mySqrt(4) will return 2
if (s == 0)
{
    cout << "The square root is 0" << endl;
}
else if (s > 0)
{
double estimate = 1.0;
double newEstimate = 0.5*(estimate + s/estimate);
while (abs(estimate - newEstimate) > 0.000001)
{
estimate = newEstimate;
newEstimate = 0.5*(estimate + s/estimate);
}
cout << "The square root is " << newEstimate << endl;
}
else
{
cout << "error" << endl;
}
return s;
}// mySqrt()

int main() {

  double s = mySqrt(5); 
  cout << s << endl; // expect 2.236

  return 0;
}// main()

