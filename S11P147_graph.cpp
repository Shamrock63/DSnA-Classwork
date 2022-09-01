#include <iostream>
#include <vector>

const int Size = 50;

// what's a getter/setter lol lmao
class Node {
public:
  int key;
  std::vector<int> adjacentList;
  Node(int k) {
    this->key = k;
  }
};

class Graph {
private:
  int numberOfNodes;
  Node **data; // dbl ptr because array shenaniganery
public:
  Graph() {
    this->data = new Node * [Size];
    // honestly unsure if this bit is necessary? Doesn't hurt I guess
    for(int i = 0; i < Size; i++) {
      data[i] = NULL;
    }
    this->numberOfNodes = 0;
  }
  void addVertex(int node) {
    if(this->data[node] == NULL) {
      this->data[node] = new Node(node);
      this->numberOfNodes++;
    } else {
      std::cout << "Node " << node << " already exists.\n";
    }
  }
  void addEdge(int node1, int node2) {
    if(this->data[node1] != NULL && this->data[node2] != NULL) {
      this->data[node1]->adjacentList.push_back(node2);
      this->data[node2]->adjacentList.push_back(node1);
    } else {
      std::cout << "One or both nodes do not exist.\n";
    }
  }
  void showConnections() {
    // Instructor example used JS magic to make a list of each node. I will be assuming all nodes are sequential starting from 0 for this function.
    for(int i = 0; i < this->numberOfNodes; i++) {
      std::string connections = "";
      int connSize = this->data[i]->adjacentList.size();
      for(int j = 0; j < connSize; j++) {
        connections += std::to_string(this->data[i]->adjacentList[j]);
        connections += " ";
      }
      std::cout << i << " -> " << connections << std::endl;
    }
  }
};

int main() {
  Graph myGraph;
  myGraph.addVertex(0);
  myGraph.addVertex(1);
  myGraph.addVertex(2);
  myGraph.addVertex(3);
  myGraph.addVertex(4);
  myGraph.addVertex(5);
  myGraph.addVertex(6);
  myGraph.addEdge(3,1);
  myGraph.addEdge(3,4);
  myGraph.addEdge(4,2);
  myGraph.addEdge(4,5);
  myGraph.addEdge(1,2);
  myGraph.addEdge(1,0);
  myGraph.addEdge(0,2);
  myGraph.addEdge(6,5);
  myGraph.showConnections();
}
