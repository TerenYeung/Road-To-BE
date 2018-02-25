#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int *x, int *y);

int main()
{
/*  int a = 10, b = 20;
  int *x = &a, *y = &b;
  swap(x, y);
  cout << "x is " << *x << " "
    << "y is " << *y << endl;
    */

  for (int a, b; cout << "Please Enter: \n", cin >> a >> b;)
  {
    swap(&a, &b);
    cout << a << " " << b << endl;
  }
  return 0;
}

void swap(int *x, int *y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}


