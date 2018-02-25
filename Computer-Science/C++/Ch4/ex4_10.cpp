#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main()
{
  int i = 0;
  // while(cin >> i) if(i == 42) break;
  while (cin >> i && i != 42);

  // ex4_11

  int a = 4, b = 3, c = 2, d = 1;
  if (a > b && b > c && c > d) cout << "good!" << endl;
  return 0;
}