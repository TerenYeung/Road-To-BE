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

  // range for
  for (const int (&row)[4] : arr)
    for (int col : row) cout << col << " ";
  cout << endl;

  // for loop
  for (size_t i = 0; i != 3; ++i)
    for (size_t j = 0; j != 4; ++j) cout << arr[i][j] << " ";
  cout << endl;

  // using pointers
  for (int (*row)[4] = arr; row != arr + 3; ++row)
    for (int *col = *row; col != *row + 4; ++col) cout << *col << " ";
    cout << endl;
  return 0;
}