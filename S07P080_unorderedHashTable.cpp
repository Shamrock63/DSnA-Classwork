#include <iostream>
#include <string>
#include <vector>

using namespace std;

//-------------------------------------------------------
// I was told to make a hash table right after being told
// that they exist. This code does not work. It is what I
// was able to figure out on my own from researching help
// documentation and cross referencing some examples.
// It didn't reach completion because I was not satisfied
// with just copying a solution from online.
//
// EDIT: Set and Get were implemented while following the
// solution presentation. Turns out the TutorialsPoint
// example needed to change != to == for the set logic to
// work properly.
//-------------------------------------------------------

// References Used (excluding documentation):
// https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
// https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus

const int Size = 50;

// What I've gathered is that a HashTable should be an array of objects. I've also seen several examples using double pointers, which scares me beyond belief.
class HashTableElement {
// It's bad form, but I'm not bothering with a getter/setter here
public:
  string eKey;
  int eVal;
  HashTableElement(string key, int val) {
    eKey = key;
    eVal = val;
  }
};

class HashTable {
private:
  // What I've gathered from this is that the table is an array of pointers, but because of Object shenaniganery, I need to point to the table itself. Therefore, double pointer. Apparently?????
  HashTableElement **data;

  // converts string to int key. Underscore before name is apparently the Java way to make private functions in an object.
  int _hash(string key) {
    int hash = 0;
    for(int i = 0; i < key.length(); i++) {
      hash = (hash + key[i] * i) % Size;
    }
    return hash;
  }

public:
  // Creates an array of elements length Size, then initializes each to NULL
  HashTable() {
    data = new HashTableElement * [Size];
    for(int i = 0; i < Size; i++) {
      data[i] = NULL;
    }
  }

  // destructor - loop through and ensure every element is deleted, then delete the table
  ~HashTable() {
    for(int i = 0; i < Size; i++) {
      if(data[i] != NULL) delete data[i];
    }
    delete[] data;
  }

  void set(string key, int val) {
    int index = _hash(key);
    if(data[index] == NULL) {
      data[index] = new HashTableElement(key, val);
    } else {
      cout << "Address already in use.\nWhat do you think this is, a Linked List?\n";
    }
  }

  int get(string key) {
    int index = _hash(key);
    if(data[index] != NULL) {
      return data[index]->eVal;
    }
    return -1;
  }
};

int main() {
  HashTable myHashTable;
  myHashTable.set("grapes",10000);
  cout << myHashTable.get("grapes") << endl;
}
