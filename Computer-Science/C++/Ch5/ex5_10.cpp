#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0, spaceCnt = 0, nextCnt = 0, tabCnt = 0;
  char ch;
  while (cin >> ch) {
    switch(ch) {
      case 'a':
      case 'A':
        ++aCnt;
        break;
      case 'e':
      case 'E':
        ++eCnt;
        break;
      case 'i':
      case 'I':
        ++iCnt;
        break;
      case 'o':
      case 'O':
        ++oCnt;
        break;
      case 'u':
      case 'U':
        ++uCnt;
        break;
      case ' ':
        ++spaceCnt;
        break;
      case '\t': // 可以通过转义序列的相应字符替换
        ++tabCnt;
        break;
      case '\n':
        ++nextCnt;
        break;
      default:
        ++otherCnt;
    }

  cout << "Number of vowel a(A): \t" << aCnt << '\n'
      << "Number of vowel e(E): \t" << eCnt << '\n'
      << "Number of vowel i(I): \t" << iCnt << '\n'
      << "Number of vowel o(O): \t" << oCnt << '\n'
      << "Number of vowel u(U): \t" << uCnt << '\n'
      << "Number of vowel spaceCnt: \t" << spaceCnt << '\n'
      << "Number of vowel tabCnt: \t" << tabCnt<< '\n'
      << "Number of vowel nextCnt: \t" << nextCnt << '\n'
      << "Number of vowel other: \t" << otherCnt << endl;
  }
  return 0;
}