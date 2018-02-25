#include <iostream>
#include <iterator>

using std::endl;
using std::cout;
using std::begin;
using std::end;
int main()
{
  constexpr size_t sz = 5;
  int arr[sz] = {0, 2, 4, 6, 8};

  // method 1
  // for (int *barr = arr, *earr = &arr[5];barr != earr; ++barr)
  // {
  //   *barr = 0;
  // }


  // method 2
  // int *barr = arr, *earr = arr + sz;
  // // 能比较的前提是两个指针指向同一个数组
  // while (barr < earr)
  // {
  //   *barr = 0;
  //   ++barr;
  // }

  // method 3
  int *barr = begin(arr), *earr = end(arr);
  while (barr != earr)
  {
    *barr = 0;
    ++barr;
  }
  
  for(auto i : arr) cout << arr[i] << " ";
  cout << endl;

  return 0;
}