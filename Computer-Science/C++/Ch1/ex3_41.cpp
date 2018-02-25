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

int main()
{
  int arr[] = {1,2,3,4,5};
  vector<int> ivec(begin(arr), end(arr));
  for(auto i : ivec) cout << i << " ";
  cout << endl;
  return 0;
}