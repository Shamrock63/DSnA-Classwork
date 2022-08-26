#include <iostream>
#include <string>
//#include <typeinfo>

using namespace std;

//O(n)
string reverse(string str) {
  //noting things the instructor suggested here
  //if(!str || str.length()==0 || typeid(str) != "string") {
  //  cout << "Invalid Input";
  //  return(str);
  //}
  string strinv = str;
  for(int i = 0; i < str.length(); i++) {
    strinv[str.length()-1-i] = str[i];
  }
  return(strinv);
}

int main(void){
  string input = "Input String";
  string output = reverse(input);
  cout << output << "\n";
}
