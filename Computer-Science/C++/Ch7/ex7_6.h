
#ifndef ex7_06_h
#define ex7_06_h

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::endl;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  string isbn() const { return bookNo; };
  Sales_data &combine(const Sales_data &);
};

// member functions.
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

// nonmember functions

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.combine(rhs);

  return sum;
}

istream &read(istream &is, Sales_data &item)
{
  double price = 0.0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
  os << item.isbn() << " "
    << item.units_sold << " "
    << item.revenue << endl;
  return os;
}
#endif