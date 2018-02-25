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
using std::string;

int main()
{
  // const char ca[] = {'h', 'e', 'l', 'l', 'o'};
  // const char *cp = ca;
  // while(*cp) {
  //   cout << *cp << endl;
  //   ++cp;
  // }
  string s1 = "Hello", s2 = "World", s3 = "World";
  cout << (s1 < s2) << " ";
  cout << (s2 == s3) << endl;

  const char ca1[] = {'H', 'e', '\0'}, ca2[] = {'H', 'a'}, ca3[] = {'H', 'e', '\0'};
  cout << strcmp(ca1, ca2) << " ";
  cout << strcmp(ca1, ca3) << endl;
  // use C-Style character strings.
  // const char* cs1 = "Wangyue";
  // const char* cs2 = "Pezy";
  // auto result = strcmp(cs1, cs2);
  // if (result == 0)
  //   cout << "same string." << endl;
  // else if (result < 0)
  //   cout << "Wangyue < Pezy" << endl;
  // else
  //   cout << "Wangyue > Pezy" << endl;

  // return 0;
  return 0;
}