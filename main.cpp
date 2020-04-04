#include "GenStack.h"
#include <iostream>

using namespace std;

int main()
{
  string filename; //user input
  GenStack s(100);
  cout << "Hello! Please input the source code file: " << endl;
  cin >> filename;
  if (s.check(filename) == true){
    cout << "No errors found." << endl;
  }
  if (s.check(filename) == false){
    return 0; //exits so the user can fix the error
  }


}
