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
  string rsp;
  do {
    cout << "Input two strings: ";
    string s1, s2;
    cin >> s1 >> s2;
    cout << (s1 <= s2 ? s1 : s2)
        << " is less than the other. " << "\n\n"
        << "More? Enter yes or no: ";
    cin >> rsp;
  } while(!rsp.empty() && tolower(rsp[0]) == 'y');
  return 0;
}
