// This is the first time in years I've thought about Java. It'll be fiiiiiiine. I'm just implementing a funky linked list after all.
// Update 1: The nanny warnings about variables I just made not being used is not appreciated, actually.
// Update 2: Yeah, a lot of this is pretty much the same conceptually. It's just the terms changing. AND NO POINTERS WOOOOOO
// Update 3: I got the two easy parts of remove done on my own. The third, I'm going to work on tomorrow.
// Update 4: Covering the edge case in replace() of the next node to the right being the successor took WAY longer than it should have to crack, but I'm fairly confident I've got it now.

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
        System.out.println("value: " + tempNode.value);
        if(tempNode.left != null) {
          System.out.println("left: " + tempNode.left.value);
        } else {
          System.out.println("left: " + tempNode.left);
        }
        if(tempNode.right != null) {
          System.out.println("right: " + tempNode.right.value);
        } else {
          System.out.println("right: " + tempNode.right);
        }
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
    int tempNodePrevDir = -1; // 0: left 1: right -1: root
    while (tempNode != null) {
      if (val == tempNode.value) {
        if (tempNode.left == null && tempNode.right == null) {
          // leaf - delete
          if (tempNodePrevDir == 1) { // prev right
            tempNodePrev.right = null;
          } else if (tempNodePrevDir == 0) { // prev left
            tempNodePrev.left = null;
          }
          System.out.println("Removed " + val + " 0C");
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
          System.out.println("Removed " + val + " 1C");
          tempNode = null;
        } else {
          // two children - find successor
          Node delNodePrev = tempNodePrev; // marking the prev node for reconnecting. If null/nothing prior, the replacement node is the new root
          tempNodePrev = tempNode;
          tempNode = tempNode.right;
          while(tempNode.left != null) {
            tempNodePrev = tempNode;
            tempNode = tempNode.left;
          }
          // at this point, delNodePrev is set to the node before it. If null, proceed as root. tempNode is the replacement node.
          if(tempNodePrevDir == -1) {
            tempNode.left = root.left;
            tempNode.right = root.right;
            root = null; // might not be needed? C brain says clearing the spot in memory is good form
            root = tempNode;
          } else if(tempNodePrevDir == 0){
            tempNode.left = delNodePrev.left.left;
            if(delNodePrev.left.right == tempNode) {
              tempNode.right = delNodePrev.left.right.right;
            } else {
              tempNode.right = delNodePrev.left.right;
            }
            delNodePrev.left = null;
            delNodePrev.left = tempNode;
          } else {
            tempNode.left = delNodePrev.right.left;
            if(delNodePrev.right.right == tempNode) {
              tempNode.right = delNodePrev.right.right.right;
            } else {
              tempNode.right = delNodePrev.right.right;
            }
            delNodePrev.right = null;
            delNodePrev.right = tempNode;
          }
          System.out.println("Removed " + val + " 2C");
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
    //         9
    //     4        20
    //   1   6   15    170
    //               169
    bST.insert(9);
    bST.insert(4);
    bST.insert(6);
    bST.insert(20);
    bST.insert(170);
    bST.insert(169);
    bST.insert(15);
    bST.insert(1);
    bST.lookup(6);
    bST.lookup(20);
    bST.lookup(21);
    bST.remove(20);
    bST.lookup(169);
  }
}
