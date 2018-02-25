#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {

  // method 1:
  vector<int> scores(10, 0);
  // unsigned grade;
  // while(cin >> grade)
  //   if (grade <= 100)
  //     ++scores[grade / 10];

  // method 2;
  // 第二个方法为什么不行
  // vector<int> grades;
  // for (decltype(grades.size()) grade; cin >> grade; grades.push_back(grade))


  // for (auto it = grades.begin(); it != grades.end(); ++it)
  // {
  //   cout << *it << endl;
  //   ++scores[*it / 10];
  // }
  // for(auto score : scores)
  //   cout << score << " ";
  // cout << endl;

  for(unsigned grade; cin >> grade;)
    if (grade <= 100)
      ++*(scores.begin() + grade / 10);

    for (auto score : scores)
      cout << score << " ";
    cout << endl;
  return 0;
}