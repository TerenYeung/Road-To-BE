#include <iostream>

using std::cout;
using std::endl;

void f()
{
  cout << "f()" << endl;
}

void f(int)
{
  cout << "f(int)" << endl;
}

void f(int, int)
{
  cout << "f(int, int)" << endl;
}

void f(double, double)
{
  cout << "f(double, double)" << endl;
}

int main() { 
  f();
  f(2);
  f(2, 2);
  f(2.0, 2.0);
  return 0;
}