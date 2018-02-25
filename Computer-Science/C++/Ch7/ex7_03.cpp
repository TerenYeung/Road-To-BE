#include <iostream>
#include "ex7_02.h"

using std::endl;
using std::cin;
using std::cerr;
using std::cout;

int main()
{
  // first input
  Sales_data total;
  if (cin >> total.bookNo >> total.units_sold >> total.revenue)
  {
    Sales_data trans;
    while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
    {
      if (total.isbn() == trans.isbn())
      {
        total.combine(trans);
      }
      else {
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
        total = trans;
      }
    }
    cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
  }
  else
  {
    cerr << "No data!." << endl;
  }
}