#include <iostream>
#include <string>
#include <cctype>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::isupper;
using std::tolower;

bool hasUpperChar(const string &str)
{
  for (auto s : str)
  {
    if (isupper(s)) {
      return true;
    }
  }
  return false;
}

void to_lowercase(string &str)
{
  for (auto &ch : str) ch = tolower(ch);
}

int main()
{
  string s("Hello World");
  cout << hasUpperChar(s) << endl;
  to_lowercase(s);
  cout << s << endl;
  return 0;
}

// ex6_18
// bool compare(matrix &m1, matrix &m2);
// vector<int>::iterator change_val(int, vector<int>::iterator);

