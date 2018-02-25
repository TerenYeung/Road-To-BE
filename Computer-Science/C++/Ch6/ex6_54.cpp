#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

inline int f(const int, const int);
typedef decltype(f) fp;
using conInt = const int;
inline int NumAdd(conInt x, conInt y) { return x + y; }
inline int NumSub(conInt x, conInt y) { return x - y; }
inline int NumMul(conInt x, conInt y) { return x * y; }
inline int NumDiv(conInt x, conInt y) { return x / y; }

vector<fp*> v {NumAdd, NumSub, NumMul, NumDiv};

int main()
{
  for(auto i : v)
    cout << (*i)(2, 3) << endl;
  return 0;
}