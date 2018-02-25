#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  vector<int> v = {0,1,2,3,4,5};
  for (auto &r : v) cout << r << " ";
  return 0;
}
