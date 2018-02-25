#include <iostream>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

int main()
{
  int a, b, result;

  while (cin >> a >> b)
  {
    try {
      if ( b == 0) throw runtime_error("divisor must not be zero.");
      result = a / b;
      cout << result << endl;
    } catch(runtime_error err) {
      cout << err.what()
          << "\nTry again ? Enter y or n" << endl;
      char c;
      cin >> c;
      if (!cin || c == 'n') break;
    }
  }
  return 0;
}