#include <iostream>

using std::cout;
using std::endl;

int main() {
  // integers type
  cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
  cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
  cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
  cout << "long long:\t\t" << sizeof(long long) << " bytes" << endl;

  // floating point type
  cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
  cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
  cout << "long double:\t\t" << sizeof(long double) << " bytes" << endl;

  // Fixed width integers
  cout << "int8_t:\t\t" << sizeof(int8_t) << " bytes" << endl;
  cout << "uint8_t:\t\t" << sizeof(uint8_t) << " bytes" << endl;
  cout << "int16_t:\t\t" << sizeof(int16_t) << " bytes" << endl;
  cout << "uint16_t:\t\t" << sizeof(uint16_t) << " bytes" << endl;
  cout << "int32_t:\t\t" << sizeof(int32_t) << " bytes" << endl;
  cout << "uint32_t:\t\t" << sizeof(uint32_t) << " bytes" << endl;
  cout << "int64_t:\t\t" << sizeof(int64_t) << " bytes" << endl;
  cout << "uint64_t:\t\t" << sizeof(uint64_t) << " bytes" << endl;

  // character type
  cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
  cout << "wchar_t:\t\t" << sizeof(wchar_t) << " bytes" << endl;
  cout << "char16_t:\t\t" << sizeof(char16_t) << " bytes" << endl;
  cout << "char32_t:\t\t" << sizeof(char32_t) << " bytes" << endl;

  // void type
  cout << "void: nullptr_t\t" << sizeof(std::nullptr_t) << " bytes" << endl;

  int x[10];
  int *p = x;
  cout << sizeof(p)/sizeof(*p) << endl;

  cout << 3 + 'a' << endl;
  return 0;
}