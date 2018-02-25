#ifndef ex7_23_h
#define ex7_23_h

#include <string>

using std::string;

class Screen {
  public:
    typedef string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }

  private:
    pos height = 0, width = 0;
    pos cursor = 0;
    string contents;
};

#endif