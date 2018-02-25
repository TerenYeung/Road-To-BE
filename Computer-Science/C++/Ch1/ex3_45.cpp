#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cstring>

using std::endl;
using std::cout;
using std::begin;
using std::end;
using std::vector;
using std::size_t;

int main()
{
  int arr[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

  // using range for
  for (auto &row : arr)
    for (auto col : row) cout << col << " ";
  cout << endl;

  // using for loop
  for (auto i = 0; i != 3; ++i)
    for (auto j = 0; j != 4; ++j) cout << arr[i][j] << " ";
  cout << endl;

  // using pointer
  for (auto row = arr; row != arr + 3; ++row)
    for (auto col = *row; col != *row + 4; ++col) cout << *col << " ";
  cout << endl;
  int a = 2;
  int * p = &a;
  cout << "p " << p << " " << "*p " << *p << endl;
  short sh_v = 32767;
  sh_v += 1;
  cout << sh_v << endl;
  cout << (a == true) << endl;
  return 0;
}