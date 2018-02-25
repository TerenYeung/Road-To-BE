#include <iostream>
#include "ex7_6.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() { 
  
  Sales_data total;
  if (read(cin, total))
  {
    Sales_data trans;
    while(read(cin, trans))
    {
      if (total.isbn() == trans.isbn())
        total = add(total, trans);
      else
      {
        print(cout, total) << endl;
        total = trans;
      }

    }
    print(cout, total) << endl;
  }
  else
  {
    cerr << "No data!." << endl;
    return -1;
  }

  return 0;
}