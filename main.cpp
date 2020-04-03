#include "GenStack.h"
#include <iostream>

using namespace std;

int main()
{

  GenStack stacky(10);

  stacky.push('b');
  cout << stacky.peek()<< endl;


  return 0;
}
