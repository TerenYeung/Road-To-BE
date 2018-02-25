#include <iostream>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using Iter = vector<int>::const_iterator;

void print(Iter first, Iter last)
{
  if (first != last)
  {
    cout << *first << " ";
    print(++first, last);
  }
}

int main(void)
{
  vector<int> ivec{1,2,3,4,5};
  print(ivec.cbegin(), ivec.cend());
  return 0;
}