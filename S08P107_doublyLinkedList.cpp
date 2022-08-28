#include <iostream>

using namespace std;

// Using linkedList.cpp as a base, I aim to modify it into a doubly linked list on my own.
// Working on remove, I found an issue with insert(). The node tailing the inserted node continued to point to the node before the insertion.

class Node {
public:
  int value;
  Node *linkH;
  Node *linkT;
  Node(int val) {
    this->value = val;
    linkH = NULL;
    linkT = NULL;
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
      tail->linkT = newNode;
      newNode->linkH = tail;
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
      newNode->linkT = head;
      head->linkH = newNode;
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
        prev = prev->linkT;
      }
      currIns->linkT = prev->linkT;
      currIns->linkH = prev;
      prev->linkT = currIns;
      currIns->linkT->linkH = currIns;
      length++;
    }
  }

  void remove(int index) {
    if(index < 0 || index+1 > length) {
      cout << "Invalid index.\n";
      return;
    }
    
    Node *temp;
    if(index == 0) {
      temp = head;
      head = head->linkT;
      head->linkH = NULL;
      free(temp);
      length--;
      return;
    } else if(index+1 == length) {
      temp = tail;
      tail = tail->linkH;
      tail->linkT = NULL;
      free(temp);
      length--;
      return;
    }

    if(index < length/2) {
      temp = head;
      int i = 0;
      while(i < index-1) {
        temp = temp->linkT;
        i++;
      }
      Node *toDel = temp->linkT;
      temp->linkT = toDel->linkT;
      toDel->linkT->linkH = temp;
      free(toDel);
      length--;
    } else {
      temp = tail;
      int i = length-1;
      while(i > index+1) {
        temp = temp->linkH;
        i--;
      }
      Node *toDel = temp->linkH;
      temp->linkH = toDel->linkH;
      toDel->linkH->linkT = temp;
      free(toDel);
      length--;
    }
  }

  void reverse() {
    Node *prevT;
    Node *temp = tail;
    for(int i = length-1; i >= 0; i--) {
      if(temp->linkT == NULL) {
        temp->linkT = temp->linkH;
        temp->linkH = NULL;
        head = temp;
      } else if(temp->linkH == NULL) {
        temp->linkH = temp->linkT;
        temp->linkT = NULL;
        tail = temp;
      } else {
        temp->linkT = temp->linkH;
        temp->linkH = prevT;
      }
      prevT = temp;
      temp = temp->linkT;
    }
  }

  void displayOne(int index) {
    Node *currDisp;
    if(index < length/2) {
      currDisp = head;
      int i = 0;
      while(i < index) {
        currDisp = currDisp->linkT;
        i++;
      }
      cout << currDisp->value << endl;
    } else {
      currDisp = tail;
      int i = length-1;
      while(i > index) {
        currDisp = currDisp->linkH;
        i--;
      }
      cout << currDisp->value << endl;
    }
  }

  void displayAll() {
    if(!head) {
      cout << "List empty.\n";
    } else {
      Node *currDisp = head;
      for(int i = 0; i < length; i++) {
        if(i) {
          cout << " -> ";
        }
        cout << currDisp->value;
        currDisp = currDisp->linkT;
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
  myLL.displayAll();

  myLL.prepend(7);
  myLL.remove(2);
  myLL.insert(1, 11);
  myLL.displayAll();

  myLL.reverse();
  myLL.displayAll();
}
