#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// int main() {
//   vector<int> ivec;
//   int n;
//   while(cin >> n) ivec.push_back(n);
//   for(auto i : ivec) cout << i << endl;
//   return 0;
// }

// int main() {
//   vector<int> ivec;
//   for (int n; cin >> n; ivec.push_back(n));
//   return 0;
// }

int main() {
  vector<string> svec;
  for(string s; cin >> s;)
    svec.push_back(s);
  return 0;
}