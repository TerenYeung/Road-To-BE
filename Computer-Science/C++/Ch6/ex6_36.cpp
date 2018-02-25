#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::string;

// normal
string (&func(string (&arrStr))[10])[10];

// type alias
// typedef string arrStr[10];
using ArrT = string[10];
Arry &func(ArrT& arrStr);

// tailing return type
auto func(string (&arrStr)[10]) -> string(&) [10];

// decltype
decltype(string [10]) &func(string (&arrStr)[10]);