
#ifndef ex7_02_h
#define ex7_02_h

#include <string>

using std::string;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  string isbn() const { return bookNo; };
  Sales_data &combine(const Sales_data &);
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

#endif