#include <iostream>
#include "ex7_27.h"

using std::cout;

int main()
{
  Screen myScreen(5, 5, 'x');
  myScreen.move(4, 0).set('#').display(cout);

  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
}
