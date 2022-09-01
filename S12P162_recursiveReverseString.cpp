#include <iostream>
#include <string>

// It feels funny going back to our very first example to implement recursion on it. Also funny that the solution I got is O(2n), so it doesn't actually save time vs the original O(n) anyways.

/* 
 * Take off the last character, and pass the rest through.
 * When the rest passed through is one character, it starts 
 * returning the substring with the former last character
 * now at the beginning.
 */
std::string reverse(std::string str) {
  int length = str.length();
  if(length <= 1) {
    return str;
  }
  std::string strBack = str.at(length-1) + reverse(str.substr(0,length-1));
  return strBack;
}

int main(void){
  std::string input = "Input String";
  std::cout << reverse(input) << std::endl;
}
