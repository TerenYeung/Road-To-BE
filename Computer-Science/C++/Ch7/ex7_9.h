#ifndef ex7_4_h
#define ex7_4_h

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::endl;
using std::cin;
using std::cout;
using std::string;

struct Person {
  string name;
  string address;

  string const& get_name() const {
  // 最后这const用于修饰该函数，表示在函数内不能改变其对应对象的成员变量的值 
    return name; }
  string const& get_addr() const { return address; }
}

istream &read(istream &is, Person &item)
{
  is >> item.name >> item.address;

  return is;
}

ostream &print(ostream &os, const Person &item)
{
  os << item.get_name() << " "
    << item.get_addr() << endl;

  return os;
}

#endif