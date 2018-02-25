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
  vector<int> ivec = {1,2,3,4,5};
  constexpr size_t sz = 5;
  int arr[sz];
  for(int i = 0; i != sz; ++i) arr[i] = ivec[i];
  for (auto i : arr) cout << i << " ";
  cout << endl;
  return 0;
}
