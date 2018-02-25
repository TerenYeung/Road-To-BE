#ifndef ex7_41_h
#define ex7_41_h

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Sales_data {
  public:
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) { cout << "Sales_data(const string &s, unsigned n, double p)" << endl;}

    Sales_data() : Sales_data("", 0, 0.0f) { cout << "Sales_data()" << endl;}

    Sales_data(const string &s) : Sales_data(s, 0, 0.0f) { cout << "Sales_data(const string &s)" << endl;}

    Sales_data(istream &is) : Sales_data() {
      cout << " " << endl;
      read(is, *this);
    }
    
    string isbn() const { return bookNo; }

    Sales_data &combine(const Sales_data&);

  private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    inline double avg_price() const;

  
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend istream &read(istream&, Sales_data&);
  friend ostream &print(ostream&, const Sales_data&);

};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data &rhs)
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
    << item.revenue;
  return os;
}

// private member functions.
inline double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

#endif