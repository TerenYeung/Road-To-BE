#include <iostream>
#include <vector>
#include <cstddef>

using std::endl;
using std::cout;
using std::vector;
using std::size_t;

int main()
{
  constexpr size_t sz = 10;
  int arr[sz], arr2[sz];
  for (auto i = 0; i < 10; ++i) arr[i] = i;
  for (auto i = 0; i < 10; ++i) arr2[i] = arr[i];

  // vector
  vector<int> v(10);
  for (int i = 0; i != 10; ++i) v[i] = i;
  vector<int> v2(v);
  for (auto i : v2) cout << i << " ";
  cout << endl;
  return 0;
}