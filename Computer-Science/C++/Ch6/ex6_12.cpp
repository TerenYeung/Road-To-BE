#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int &x, int &y)
{
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}

int main()
{
  int a = 10, b = 20;
  swap(a, b);
  cout << "after swaping of a and b: " << a << " " << b << endl;
  return 0;
}