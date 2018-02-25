#include <iostream>
#include "ex7_41.h"

int main() { 
  Sales_data s1;

  Sales_data s2("Cpp");

  Sales_data s3("Cpp", 5, 5.2);

  Sales_data s4(std::cin);  
  return 0;
}