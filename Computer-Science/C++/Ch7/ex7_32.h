#ifndef ex7_32_h
#define ex7_32_h

#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;

using std::vector;

class Screen {
  public:
    typedef string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }

    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os) { do_display(os); return *this; }
    const Screen &display(ostream &os) const { do_display(os); return *this; }

  private:
    pos height = 0, width = 0;
    pos cursor = 0;
    string contents;

    void do_display(ostream &os) const { os << contents; }

  friend class Window_mgr;
};

inline Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;

  return *this;
}

inline Screen &Screen::set(char c)
{
  contents[cursor] = c;

  return *this;
}

inline Screen &Screen::set(pos row, pos col, char c)
{
  contents[row * width + col] = c;

  return *this;
}

class Window_mgr {
  public:
    using screen_index = vector<Screen>::size_type;

    incline void clear(screen_index);
  
  private:
    vector<Screen> screens {Screen(5, 5, ' ')};
}

incline void Window_mgr::clear(screen_index i)
{
  if(i > screens.size()) return;
  Screen &item = screens[i];
  
  item.contents = string(item.height * item.width, ' ');
}


#endif