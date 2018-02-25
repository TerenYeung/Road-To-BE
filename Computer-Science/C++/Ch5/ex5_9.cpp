#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  unsigned int ac = 0, ec = 0, ic = 0, oc = 0, uc = 0, otherc = 0;
  char ch;
  while(cin >> ch){
    if (ch == 'a' || ch == 'A') ++ac;
    else if (ch == 'e' || ch == 'E') ++ec;
    else if (ch == 'i' || ch == 'I') ++ic;
    else if (ch == 'o' || ch == 'O') ++oc;
    else if (ch == 'u' || ch == 'U') ++uc;
    else ++otherc;
  }

  cout << "ac:\t" << ac << endl;
  cout << "ec:\t" << ec << endl;
  cout << "ic:\t" << ic << endl;
  cout << "oc:\t" << oc << endl;
  cout << "uc:\t" << uc << endl;
  return 0;
}