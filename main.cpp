#include "GenStack.h"
#include <iostream>

using namespace std;

int main()
{
  string filename; //user input
  GenStack s(100);
  char r = 'Y'; //response var
  string filename2; //dummy var
  cout << "Hello! Please input the source code file: " << endl;
  cin >> filename;
    while (s.check(filename) == true){ //loop so they can keep checking
      cout << "No errors found." << endl;
      cout << "Would you like to analyze another file?" << endl;
      cout << " Type 'Y' for yes, or 'N' for no." << endl;
      cin >> r;
      if(r == 'Y'){
        cout << "Please input the source code file: " << endl;
        cin >> filename2;
        filename = filename2;
        s.check(filename);
      }
      if(r == 'N'){
        return 0;
      }
    }
    if (s.check(filename) == false){
      return 0; //exits so the user can fix the error
    }

}
