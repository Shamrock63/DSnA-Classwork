// PROMPT:
// [2,5,1,2,3,5,1,2,4]
// 2
// [2,1,1,2,3,5,1,2,4]
// 1
// [2,3,4,5]
// undef
//
// Possible values is not specified.
//   Based on leetCode, I should assume [1,n]
// Perms to modify array not specified, but I should avoid
//
// In hindsight, this looks a lot like I'm not utilizing HashTable properly... Like, this could just be an array/vector. At least this allows me to preconstruct the functions? I guess?

#include <iostream>
#include <vector>

using namespace std;

const int Size = 50;

class firstRecurringCharacter {
private:
  vector<int> intSeen;

public:
  firstRecurringCharacter(int n) {
    for(int i = 0; i < n; i++) {
      intSeen.push_back(0);
    }
  }

  int fRC(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
      if(intSeen[arr[i]] == arr[i]) {
        return arr[i];
      } else {
        intSeen[arr[i]] = arr[i];
      }
    }
    return -1;
  }

  void clearSeen() {
    for(int i = 0; i < intSeen.size(); i++) {
      intSeen[i] = 0;
    }
  }
};

int main() {
  int p1[] = {2,5,1,2,3,5,1,2,4};
  int p2[] = {2,1,1,2,3,5,1,2,4};
  int p3[] = {2,3,4,5};
  // I'm trying to be more clever than I should be at this stage. Setting the max value as a constant instead for now.
  // max_element(prompt1, sizeof(prompt1)/sizeof(prompt1[0]));
  firstRecurringCharacter firstRC(Size);
  cout << firstRC.fRC(p1, sizeof(p1)/sizeof(p1[0])) << endl;
  firstRC.clearSeen();
  cout << firstRC.fRC(p2, sizeof(p2)/sizeof(p2[0])) << endl;
  firstRC.clearSeen();
  cout << firstRC.fRC(p3, sizeof(p3)/sizeof(p3[0])) << endl;
}
