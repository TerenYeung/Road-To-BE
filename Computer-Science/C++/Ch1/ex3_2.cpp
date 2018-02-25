#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

// int main() {
//   string s;
//   cin >> s;
//   cout << s << endl;
//   return 0;
// }

// int main() {
//   string word;
//   while (cin >> word)
//     cout << word << endl;
//   return 0;
// }

// int main() {
//   string line;
//   while (getline(cin, line))
//     // cout << line.empty() << endl;
//     cout << "size of line is " << line.size() << endl;
//     if (!line.empty())
//       cout << line << endl;
//   return 0;
// }

int main () {
  for(string line; getline(cin, line, ';'); cout << line << endl);
  return 0;
}

// int main () {
//   for(string word; cin >> word; cout << word << endl;)
//   return 0;
// }

