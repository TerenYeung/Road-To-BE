#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  string str("Hello World");

  // range for
  for (auto &c : str) c = 'X';
  cout << str << endl;

  // while
  decltype(str.size()) i = 0;
  while(i < str.size()) str[i++] = 'Y';
  cout << str << endl;

  // for
  for (i = 0; i < str.size(); ++i) str[i] = 'Z';
  cout << str << endl;
  return 0;
}