#include <iostream>
#include <string>

using std::istream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

istream &read(istream &is)
{
  string buffer;
  while(cin >> buffer)
    cout << buffer << endl;
  is.clear();
  cout << is.rdstate() << endl;
  cout << is.bad() << " " << is.fail() << " " << is.good() << endl;
  return is;
}

int main() { 
  read(cin);
  return 0;
}