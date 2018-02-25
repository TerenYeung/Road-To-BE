#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;

int main()
{
  for(unsigned g; cin >> g;)
  {
    auto result = g > 90 ? "high pass" : g < 60 ? "fail" : g < 75 ? "low pass" : "pass";

    if (g > 90) cout << "high pass";
    else if (g < 60) cout << "fail";
    else if (g < 75) cout << "low pass";
    else cout << "pass";
    cout << endl;
  }

  cout << 1UL << endl;
  return 0;
}