#include <iostream>

using namespace std;

// This is the first time I worked with shree1999's examples. I had a fair bit of the logic already sorted, but some C++ specific trips - namely how to set up Node variables - kept catching me. In the end, I ended up doing a lot of back-and-forth of writing a bit and checking that bit against known working code.

class Node {
public:
  int value;
  Node *link;
  Node(int val) {
    this->value = val;
    link = NULL;
  }
};

class LinkedList {
//private:
public:
  // These are single pointers rather than double because they are not arrays. Makes sense in hindsight.
  Node *head;
  Node *tail;
  int length;

//public:
  LinkedList() {
    head = NULL;
    tail = NULL;
    length = 0;
  }

  void append(int val) {
    Node *newNode = new Node(val);
    if(!head) {
      head = newNode;
      tail = newNode;
      length++;
    } else {
      tail->link = newNode;
      tail = newNode;
      length++;
    }
  }

  void prepend(int val) {
    Node *newNode = new Node(val);
    if(!head) {
      head = newNode;
      tail = newNode;
      length++;
    } else {
      newNode->link = head;
      head = newNode;
      length++;
    }
  }

  void insert(int index, int val) {
    if(index < 0) {
      cout << "Invalid index.\n";
      return;
    } else if (index == 0) {
      prepend(val);
    } else if (index >= length) {
      append(val);
    } else {
      Node *currIns = new Node(val);
      Node *prev = head;
      for(int i = 0; i < index - 1; i++) {
        prev = prev->link;
      }
      currIns->link = prev->link;
      prev->link = currIns;
      length++;
    }
  }

  void remove(int index) {
    if(index < 0 || index+1 > length) {
      cout << "Invalid index.\n";
      return;
    }
    Node *temp = head;
    if(index == 0) {
      head = head->link;
      free(temp);
      length--;
      return;
    }
    int i = 0;
    while(i < index-1) {
      temp = temp->link;
      i++;
    }
    Node *toDel = temp->link;
    temp->link = toDel->link;
    free(toDel);
    length--;
  }

  void display() {
    if(!head) {
      cout << "List empty.\n";
    } else {
      Node *currDisp = head;
      for(int i = 0; i < length; i++) {
        if(i) {
          cout << " -> ";
        }
        cout << currDisp->value;
        currDisp = currDisp->link;
      }
      cout << endl;
    }
  }
};

int main() {
  LinkedList myLL;
  myLL.append(10);
  myLL.append(5);
  myLL.append(16);
  myLL.display();

  myLL.prepend(7);
  myLL.remove(2);
  myLL.insert(1, 11);
  myLL.display();
}
