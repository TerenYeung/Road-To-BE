#include <iostream>

int main() {
  int a = 1;
  int &r = a;

  std::cout << "1 is " << r << std::endl;
  
  r = 2;

  std::cout << "2 is " << r << std::endl;
  
  a = 3;
  std::cout << "3 is " << r << std::endl;
  return 0;
}


