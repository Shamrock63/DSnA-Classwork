#include <iostream>
#include <vector>

// I'm going to be a big boy and not use namespace this time. It's not like this gets significantly harder or anything. I just need to be more diligent.
// Edit: I am two lines in. This is such a drag.
// using namespace std;

class Stack {
private:
  std::vector<std::string> stackVect;
  int length; 
public:
  Stack() {
    length = 0;
  }
  void push(std::string val) {
    stackVect.push_back(val);
    length++;
  }
  std::string peek() {
    if(length) {
      return stackVect[length-1];
    } else {
      return "[WARNING] Stack is currently empty.";
    }
  }
  void pop() {
    if(length) {
      stackVect.pop_back();
    length--;
    } else {
      std::cout << "[WARNING] Stack is currently empty.\n";
    }
  }
};

int main() {
  Stack mS;
  mS.push("Googoo");
  mS.push("Abbal");
  mS.push("eBeigh");
  std::cout << mS.peek() << std::endl;
  mS.pop();
  mS.pop();
  std::cout << mS.peek() << std::endl;
  mS.pop();
  std::cout << mS.peek() << std::endl;
  mS.pop();
}
