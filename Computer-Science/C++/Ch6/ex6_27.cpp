#include <iostream>
#include <string>
#include <iterator>
#include <initializer_list>

using std::endl;
using std::cin;
using std::cout;
using std::initializer_list;
using std::begin;
using std::string;
using std::end;
using std::size_t;

int add(initializer_list<int> const &il)
{
  int ret = 0;
  for(const int i : il) ret += i;
  return ret;
}

int main() { 
  initializer_list<int> il = {1,2,3,4,5,8,10};
  cout << add(il) << endl;
  return 0;
}