#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> v1(10, 42);
  vector<int> v2{42, 42, 42,42 ,42, 42, 42, 42,42 ,42};
  vector<int> v3;
  for (int i = 0; i!= 10; ++i) v3.push_back(42);
  return 0;
}