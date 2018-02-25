#include <iostream>
#include <iterator>
#include <vector>
#include <cstring>

using std::endl;
using std::cout;
using std::begin;
using std::end;
using std::vector;

// bool compare(int *const pb1, int *const pe1, int *const pb2, int *const pe2)
// {
//   if ((pb1 - pe1) != (pb2 - pe2))
//     return false;
//   else
//   {
//     for (int *i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
//       if( *i != *j) return false;
//   }
//   return true;
// }

// int main()
// {
//   int arr1[9], arr2[9], arr3[9];
//   for(int i = 0; i != 10; i++)
//   {
//     arr1[i] = i;
//     arr2[i] = i;
//     arr3[i] = i * i;
//   }

//   // 如果两个数组长度不一样，则返回；
//   if (compare(begin(arr1), end(arr1), begin(arr3), end(arr3)))
//     cout << "The two arrays are equal." << endl;
//   else 
//     cout << "The two arrays are not equal." << endl;
//   return 0;
// }

// ex3_36b

bool compare(vector<int> v1, vector<int> v2)
{
  if (v1.size() != v2.size())
    return false;
  else
    for(auto i = v1.begin(), j = v2.begin(); (i != v1.end() && j != v2.end()); ++i, ++j)
    {
      if (*i != *j) return false;
    }
  return true;
}

int main()
{
  vector<int> v1(10, 1);
  vector<int> v2(10, 1);
  // if (v1 == v2)
  if (compare(v1, v2))
    cout << "The two vectors are equal." << endl;
  else 
    cout << "The two vectors are not equal." << endl;
  return 0;
}

// void handle(int *arr){
//   arr[2] = 4;
// }

// int main(){
//   int arr[] = {1,2,3};
//   handle(arr);
//   cout << arr[2] << endl;
//   return 0;
// }
