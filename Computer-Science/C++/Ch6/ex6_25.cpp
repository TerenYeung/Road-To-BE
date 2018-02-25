#include <iostream>
#include <string>
#include <iterator>
using std::endl;
using std::cin;
using std::cout;
using std::begin;
using std::string;
using std::end;
using std::size_t;

// int *argv[]
// argv 是一个指向数组首元素的指针，这个数组的所有元素是指针并且指向 C 风格的字符串数组
int main(int argc, char *argv[])
{
  string str;
  cout << argv[1] << endl;
  for (int i = 1; i != argc; ++i)
    str += string(argv[i]) + " ";
  cout << str << endl;
}