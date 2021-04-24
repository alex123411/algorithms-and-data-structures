#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

typedef Node *NodePtr;

class RedBlackTree {
   private:
  NodePtr root;
  NodePtr TNULL;

  void initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
  }

  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          cout << "RECOLORING !" << endl;
          cout << u->data << "|" << k->parent->data << "|" << k->parent->parent->data << endl;
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            cout <<"Rotate right " ;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          cout <<"Rotate left " <<k->data;
          leftRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          cout << "RECOLORING !" << endl;
          cout << u->data << "|" << k->parent->data << "|" << k->parent->parent->data << endl;
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            cout <<"Rotate left ";
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          cout <<"Rotate right " <<k->data;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    if(root->color == 1){
    cout << "Root`s color was changed make it black again" << endl;
    }
    root->color = 0;
  }

   public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }


  void leftRotate(NodePtr x) {
    if (x->data!=0)
    {
      cout << " " << x->data;
    }
    if (x->left->data!=0)
    {
      cout << " " << x->left->data;
    }
    if (x->right->data!=0)
    {
      cout << " " << x->right->data;
    }
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
      cout << endl;
  }

  void rightRotate(NodePtr x) {
    if (x->data!=0)
    {
      cout << " " << x->data;
    }
    if (x->left->data!=0)
    {
      cout << " " << x->left->data;
    }
    if (x->right->data!=0)
    {
      cout << " " << x->right->data;
    }
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
    cout << endl;
  }

  // Inserting a node
  void insert(int key) {
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if(x->data== key){return;}
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot() {
    return this->root;
  }
};

static void printValueOnLevel( Node* node, char pos, int depth)
{
   for (int i = 0; i < depth; i++) {
       printf("....");
   }
   printf("%c: ", pos);

   if (node == nullptr) {
       printf("(null)\n");
   } else {
       cout<<node->data<<"("<<node->color<<")"<<endl;
   }
}

static void printNode(Node * node, char pos, int depth)
{  
   bool hasChild = node != nullptr 
                       && (node->left != nullptr || node->right != nullptr);
   if (hasChild) printNode(node->right, 'R', depth + 1);
   printValueOnLevel(node, pos, depth);
   if (hasChild) printNode(node->left,  'L', depth + 1);
}

void printBinTree(Node * root) { printNode(root, '+', 0); }

int main() {
  RedBlackTree bst;
  string command;
       int k = 0;
       int ar[100];
       int i = 0;
      while (1)
      {
            cout << "1 - insert\n2 - exit" << endl; 
            cin >> command;
            if (command == "1")
            {
                  cout <<"---------------------"<< endl;
                  cin >> k;
                  bst.insert(k);
                  NodePtr node = bst.getRoot();
                  printBinTree(node);
                  cout <<"---------------------"<< endl;
            }
            else if(command == "2")
            {
                  exit (1);
            }
      }
}

