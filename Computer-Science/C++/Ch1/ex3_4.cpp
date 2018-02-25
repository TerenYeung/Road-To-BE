#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// int main() {
//   string s1, s2;
//   cin >> s1 >> s1;
//   if (s1 == s2)
//     cout << s1 << endl;
//   else if (s1 > s2)
//     cout << s1 << endl;
//   else
//     cout << s2 << endl;
//   return 0;
// }


// int main () {
//   string s1, s2;
//   while(cin >> s1 >> s2) {
//     if (s1 == s2)
//       cout << "The two strings have the same length." << endl;
//     else
//       cout << "The longer string is " << ((s1 > s2) ? s1 : s2);
//   }
//   return 0;
// }

int main() {
  string s1, s2;

  while (cin >> s1 >> s2)
    if (s1.size() == s2.size())
      cout << "The size of two strings is equal." << endl;
    else
      cout << "The larger size of two strings is " << ((s1.size() > s2.size()) ? s1 : s2);
  return 0;
}