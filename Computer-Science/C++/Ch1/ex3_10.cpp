#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// int main() {
//   string str("This is a C++ Program, so I love it."), ret;
//   for(auto c : str)
//     if(!ispunct(c)) ret += c;
//   cout << ret << endl;
//   return 0;
// }

int main()
{
    cout << "Enter a string of characters including punctuation." << endl;
    for (string s; getline(cin, s);)
        for (auto i : s) 
            if (!ispunct(i)) cout << i;

    return 0;
}