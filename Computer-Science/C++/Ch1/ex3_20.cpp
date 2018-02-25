#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
int main () {
  vector<int> ivec;
  int n;
  for (int i = 0; cin >> n; ++i) {
    ivec.push_back(n);
    cout << "Now the item is " << n << endl;
    if (ivec.size() >= 2)
      cout << "The sum of current item and next item is " << ivec[i - 1] + ivec[i] << endl;
  }
  return 0;
}
*/

// int main()
// {
//     vector<int> ivec;
//     for (int i; cin >> i; ivec.push_back(i));

//     if (ivec.empty())
//     {
//         cout << "input at least one integer." << endl;
//         return -1;
//     }

//     if (ivec.size() == 1)
//     {
//         cout << "only one integer " << ivec[0] << ", it doesn't have any adjacent elements." << endl;
//         return -1;
//     }

//     for (int i = 0; i < ivec.size() - 1; ++i)
//         cout << ivec[i] + ivec[i + 1] << " ";
//     cout << endl;
    
//     return 0;
// }

// int main () {
//   vector<int> ivec;
//   int n;
//   for (int i = 0; cin >> n; ++i) {
//     ivec.push_back(n);
//     cout << "Now the item is " << n << endl;
//     if (ivec.size() >= 2)
//       cout << "The sum of first item and last item is " << ivec[i - 2] + ivec[ivec.size() - 1] << endl;
//     else if (ivec.size() == 1)
//       cout << ivec[0] << endl;
//     else
//       cout << "(null)" << endl;
//   }
//   return 0;
// }

int main() {

  vector<int> ivec;
  for (int i; cin >> i; ivec.push_back(i));

  if (!ivec.size()) {
    cout << "input at least one interger." << endl;
    return -1;
  }

  auto size = ivec.size();
  if (size % 2 == 0)
    size /= 2;
  else
    size = size / 2 + 1;
  
  for (int i = 0; i != size; ++i)
    cout << ivec[i] + ivec[ivec.size() - i - 1] << " ";
  cout << endl;
  return 0;
}