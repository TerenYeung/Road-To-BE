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
  int arr[3][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
  };

  using int_array_4 = int[4];
  // typedef int int_array_4[4];

  // using range for
  for (int_array_4 &row : arr)
    for(int col : row) cout << col << " ";
  cout << endl;

  // using pointer
  for (int_array_4 *row = arr; row != arr + 3; ++row)
    for(int *col = *row; col != *row + 4; ++col) cout << *col << " ";
  cout << endl;
}