#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  string str, word;
  for (string str = ""; cin >> word; cout << (str += (str.empty() ? "" : " ") + word) << endl);
  // cout << "The\tis\ta\tC++\tProgram.";
  return 0;
}