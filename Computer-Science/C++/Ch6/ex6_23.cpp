#include <iostream>
#include <iterator>
using std::endl;
using std::cin;
using std::cout;
using std::begin;
using std::end;
using std::size_t;

void print(const int x)
{
  cout << "Parameter(s): " << x << endl;
}

void print(int (&arr)[2])
{
  for (auto i : arr) cout << i << " ";
  cout << endl;
}

void print(const int *ia, size_t sz)
{
  for (size_t i = 0; i != sz; ++i) cout << ia[i] << " ";
  cout << endl;
}

void print(const int *beg, const int *end)
{
  while(beg != end)
    cout << *beg++ << " ";
  cout << endl;
}

int main() { 
  int i = 0, j[2] = {0, 1};
  print(i);
  print(j);
  print(j, end(j) - begin(j));
  print(begin(j), end(j));
  return 0;
}