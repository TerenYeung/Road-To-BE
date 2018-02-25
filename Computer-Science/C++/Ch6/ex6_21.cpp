#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int compare(const int x, const int *const y)
{
  return (x <= *y) ? *y : x;
}

int main()
{
  cout << "Please input two integers." << endl;
  for(int a, b; cin >> a >> b;)
  {
    cout << "The bigger of a and b is " << compare(a, &b) << endl;
  }
  return 0;
}