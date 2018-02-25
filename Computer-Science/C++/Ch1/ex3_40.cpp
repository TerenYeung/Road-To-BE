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
using std::size_t;

int main() {
  const char cstr1[] = "Hello";
  const char cstr2[] = "world";
  // 无法编译成功
  constexpr size_t new_size = (strlen(cstr1) + strlen(" ") + strlen(cstr2) +1);
  char str[new_size];

  strcpy(str, cstr1);
  strcat(str, " ");
  strcat(str, cstr2);

  cout << str << endl;
  return 0;
}