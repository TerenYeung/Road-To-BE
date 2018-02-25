#include <iostream>
#include <vector>

#define NDEBUG

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void printVec(vector<int> &vec)
{
  #ifndef NDEBUG
    cout << "vector size: " << vec.size() << endl;
  #endif
  if (!vec.empty())
  {
    auto tmp = vec.back();
    vec.pop_back();
    printVec(vec);
    cout << tmp << " ";
  }
}

int main()
{
  vector<int> vec{1,2,3};
  printVec(vec);
  return 0;
}