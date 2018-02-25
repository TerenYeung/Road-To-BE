#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::iterator;

// int main()
// {
//   vector<int> ivec;

//   for(unsigned i = 0; i != 10; ++i) ivec.push_back(i);

//   for (auto it = ivec.begin(); it != ivec.end(); ++it) *it *= 2;

//   for (auto i : ivec) cout << i << " ";
//   return 0;
// }

// ex3_20a
/*
int main()
{
  // 从 istream 中读入一组整数
  vector<int> ivec;
  for(int buffer; cin >> buffer; ivec.push_back(buffer));

  if (ivec.size() < 2)
  {
    cout << " please enter at lease two integers.";
    return -1;
  }

  // 将每对相邻的整数和输出
  for(auto it = ivec.cbegin(); (it + 1) != ivec.cend(); ++it)
  {
    cout << *it + *(it + 1) << " ";
  }
  cout << endl;

  return 0;
}
*/

// ex3_20b
// 1. 先获取输入的一组整数
// 2. 对获取的整数进行迭代计算并输出

int main ()
{
  vector<int> ivec;

  for(int buffer; cin >> buffer; ivec.push_back(buffer));

  if (ivec.size() < 2)
  {
    cout << " please enter at lease two integers.";
    return -1;
  }

  for (auto lft = ivec.cbegin(), rht = ivec.cend() - 1; lft <= rht; ++lft, --rht)
    cout << *lft + *rht << " ";
  cout << endl;
  return 0;
  // vector::size_type size = ivec.size();
  // decltype(ivec.size()) size = ivec.size();
  // auto size = ivec.size();
}

