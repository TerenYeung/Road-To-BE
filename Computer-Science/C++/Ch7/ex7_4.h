#ifndef ex7_4_h
#define ex7_4_h

#include <string>

using std::string;

struct Person {
  string name;
  string address;

  string const& get_name() const {
  // 最后这const用于修饰该函数，表示在函数内不能改变其对应对象的成员变量的值 
    return name; }
  string const& get_addr() const { return address; }
}

#endif