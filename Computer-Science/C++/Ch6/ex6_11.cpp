#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void reset(int &x)
{
  x = 0;
}

int main()
{
  int a = 10;
  cout << "before: " << a << endl;
  reset(a);
  cout << "after: " << a << endl;
  return 0;
}