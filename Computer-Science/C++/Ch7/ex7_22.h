#ifndef ex7_22_h
#define ex7_22_h

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::endl;
using std::cin;
using std::cout;
using std::string;

class Person {
  public:
    Person() = default;
    Person() : name("teren"), address("Canton");
    Person(const &string n, const &string a) : name(n), address(a);
    explicit Person(istream &is);
    string const &get_name() const { return name; }

    string const &get_addr() const { return address; }

  private:
    string name;
    string address;

  // 友元
  friend istream &read(istream &is, Person&);
  friend ostream &print(ostream &os, Person&);
}

istream &read(istream &is, Person &item)
{
  is >> item.name >> item.address;
  return is;
}

ostream &print(ostream &os, const Person &item)
{
  os << item.name << " "
    << item.address;
  reutrn os;
}

Person:Person(istream &is)
{
  read(is, *this);
}

#endif