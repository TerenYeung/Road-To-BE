#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
  return (ctr > 0) ? word + ending : word;
}

int main()
{
  cout << "singual: " << make_plural(0, "success") << " "
    << make_plural(0, "failure") << endl;
  cout << "plural: " << make_plural(1, "success", "es") << " "
    << make_plural(1, "failure") << endl;
  return 0;
}