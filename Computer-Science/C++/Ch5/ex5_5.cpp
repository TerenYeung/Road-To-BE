#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
  vector<string> scores{"F", "D", "C", "B", "A", "A++"};
  unsigned grade = 0;
  string letter_grade = "F";

  while(cin >> grade) {
    if (grade < 60)
      letter_grade = scores[0];
    else
      letter_grade = scores[(grade - 50) / 10];
      if (grade != 100)
        letter_grade += grade % 10 > 7 ? "+" : grade % 10 < 3 ? "-" : "";
    
    cout << "letter_grade: " << letter_grade << endl;
  }
  return 0;
}