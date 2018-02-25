#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;

int main()
{
  vector<int> ivec{1,2,3,4,5,6};

  // for(auto i : ivec) cout << (i % 2 == 0 ? i : i * 2) << " ";
  for (auto i : ivec) cout << ((i & 1) ? i * 2 : i) << " ";
  cout << endl;
  return 0;
}