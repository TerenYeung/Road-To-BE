#include <iostream>

using std::endl;
using std::cin;
using std::cout;

void swap(int*& x, int*& y)
{
  int *tmp = nullptr;
  tmp = x;
  x = y;
  y = tmp;
}

int main() {
  int a = 12, b = 32;
  int *p1 = &a, *p2 = &b;
  cout << "before swap: " << *p1 << " " << *p2 << endl;
  swap(p1, p2);
  cout << "after swap: " << *p1 << " " << *p2 << endl;
  return 0;
}