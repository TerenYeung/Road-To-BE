#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::isalpha;

int main()
{
  vector<string> text;
  for (string s; getline(cin, s); text.push_back(s));

  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
  {
    for(auto &c : *it)
      if (isalpha(c)) c = toupper(c);
    cout << *it << endl;
  }

  return 0;
}

// int main() {
//   vector<string> text;
//   for (string s; getline(cin, s); text.push_back(s));

//   for (auto & word : text)
//   {
//     for (auto &ch : word)
//       if (isalpha(ch)) ch = toupper(ch);
//     cout << word << endl;
//   }

//   return 0;
// }