// This is the first time in years I've thought about Java. It'll be fiiiiiiine. I'm just implementing a funky linked list after all.
// Update 1: The nanny warnings about variables I just made not being used is not appreciated, actually.
// Update 2: Yeah, a lot of this is pretty much the same conceptually. It's just the terms changing. AND NO POINTERS WOOOOOO
// Update 3: I got the two easy parts of remove done on my own. The third, I'm going to work on tomorrow.

class Node {
  public Node left;
  public Node right;
  public int value;

  public Node(int val) {
    this.value = val;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  private Node root = null;

  // private int nodeCount;
  public BinarySearchTree() {
    // nodeCount = 0;
  }

  public void insert(int val) {
    Node newNode = new Node(val);
    if (root == null) {
      this.root = newNode;
      return;
    }

    Node tempNode = root;
    while (tempNode != null) {
      if (newNode.value == tempNode.value) {
        System.out.println("This node already exists.");
        return;
      } else if (newNode.value > tempNode.value) {
        if (tempNode.right == null) {
          tempNode.right = newNode;
          // nodeCount++;
          return;
        } else {
          tempNode = tempNode.right;
        }
      } else {
        if (tempNode.left == null) {
          tempNode.left = newNode;
          // nodeCount++;
          return;
        } else {
          tempNode = tempNode.left;
        }
      }
    }
  }

  // I can already tell one of the things we'll need to address is the possibility
  // of going down a wrong branch. I doubt that's something we're addressing right
  // away, though.
  public void lookup(int val) {
    if (root == null) {
      System.out.println("This tree is currently empty.");
      return;
    }
    Node tempNode = root;
    while (tempNode != null) {
      if (val == tempNode.value) {
        System.out.println(tempNode.value);
        return;
      } else if (val > tempNode.value) {
        if (tempNode.right == null) {
          System.out.println("This node does not exist.");
          return;
        } else {
          System.out.println(tempNode.value + " ->");
          tempNode = tempNode.right;
        }
      } else {
        if (tempNode.left == null) {
          System.out.println("This node does not exist.");
          return;
        } else {
          System.out.println("<- " + tempNode.value);
          tempNode = tempNode.left;
        }
      }
    }
  }

  public void remove(int val) {
    if (root == null) {
      System.out.println("This tree is currently empty.");
      return;
    }
    Node tempNode = root;
    Node tempNodePrev = null; // if this returns null, tempNode is still root
    int tempNodePrevDir = -1; // 0: left 1: right -1: N/A
    while (tempNode != null) {
      if (val == tempNode.value) {
        if (tempNode.left == null && tempNode.right == null) {
          // leaf - delete
          if (tempNodePrevDir == 1) { // prev right
            tempNodePrev.right = null;
          } else if (tempNodePrevDir == 0) { // prev left
            tempNodePrev.left = null;
          }
          System.out.println("Removed " + val);
          tempNode = null;
        } else if ((tempNode.left == null && tempNode.right != null)
            || (tempNode.left != null && tempNode.right == null)) {
          // one child - bypass
          if (tempNodePrevDir == 1) { // prev right
            if (tempNode.left == null) {
              tempNodePrev.right = tempNode.right;
            } else {
              tempNodePrev.right = tempNode.left;
            }
          } else if (tempNodePrevDir == 0) { // prev left
            if (tempNode.left == null) {
              tempNodePrev.left = tempNode.right;
            } else {
              tempNodePrev.left = tempNode.left;
            }
          }
          System.out.println("Removed " + val);
          tempNode = null;
        } else {
          // two children - find successor
          System.out.println("Can't currently delete node with two children.");
        }
        return;
      } else if (val > tempNode.value) {
        if (tempNode.right == null) {
          System.out.println("This node does not exist.");
          return;
        } else {
          System.out.println(tempNode.value + " ->");
          tempNodePrev = tempNode;
          tempNodePrevDir = 1;
          tempNode = tempNode.right;
        }
      } else {
        if (tempNode.left == null) {
          System.out.println("This node does not exist.");
          return;
        } else {
          System.out.println("<- " + tempNode.value);
          tempNodePrev = tempNode;
          tempNodePrevDir = 0;
          tempNode = tempNode.left;
        }
      }
    }
  }
}

public class Main {
  public static BinarySearchTree bST;

  public static void main(String[] args) {
    bST = new BinarySearchTree();
    bST.insert(9);
    bST.insert(4);
    bST.insert(6);
    bST.insert(20);
    bST.insert(170);
    bST.insert(15);
    bST.insert(1);
    bST.lookup(6);
    bST.lookup(20);
    bST.lookup(21);
    bST.remove(170);
    bST.remove(20);
    bST.lookup(15);
  }
}
