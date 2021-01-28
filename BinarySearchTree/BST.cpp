/*
PROBLEM STATEMENT:
Create a binary search tree with all its methods
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;

class Node {
  public:
    int data;
    Node *right;
    Node *left;
};

class BST {
  int size;
  Node* root;
  public:
    BST() {
      root = NULL;
      size = 0;
    }
    Node* createNode(int key) {
      Node* newNode = new Node();
      newNode->data = key;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
    }
    Node* insertNode(Node* rootNode, int key ) {
      if(!rootNode) {
        Node* newNode = createNode(key);
        root = newNode;
        return root;
      } else {
        if(key < rootNode->data) {
          if(!rootNode->left) {
            rootNode->left = createNode(key);
            return rootNode->left;
          }
          insertNode(rootNode->left, key);
        } else {
          if(!rootNode->right) {
            rootNode->right = createNode(key);
            return rootNode->right;
          }
          insertNode(rootNode->right, key);
        }
      }
      return root;
    }

    void inOrderTraverse(Node* root) {
      if(root == NULL) return;
      inOrderTraverse(root->left);
      cout << root->data << "\t";
      inOrderTraverse(root->right);
    }

    void preOrderTraverse(Node* root) {
      if(!root) return;
      cout << root->data << "\t";
      preOrderTraverse(root->left);
      preOrderTraverse(root->right);
    }

    void postOrderTraverse(Node* root) {
      if(!root) return;
      postOrderTraverse(root->left);
      postOrderTraverse(root->right);
      cout << root->data << "\t";
    }

    void BFS(Node* root) {
      if(root == NULL) {
        cout << "Empty tree!!!" << endl;
        exit(0);
      } 
      queue<Node*> q;

      q.push(root);

      while(!q.empty()) {
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        cout << q.front()->data << "\t";
        q.pop();
      }
    }

    Node* searchNode(Node* root, int key) {
      if(!root) {
        cout << "Empty tree!" << endl;
        exit(0);
      }
      Node* out = NULL;
      if(key == root->data){
         out = root;
         return out;
         }
      if(key < root->data) {
        searchNode(root->left, key);
      } else {
        searchNode(root->right, key);
      }
      return out;
    }

    int findMax(Node* root) {
      if(!root) return -1;
      while(root->right != NULL) {
        root = root->right;
      }
     return root->data;
    }

    int findMin(Node* root) {
      if(!root) return -1;
      while(root->left != NULL) {
        root = root->left;
      }
      return root->data;
    }

    Node* deleteNode(Node* &root, int key) {
      if(!root) return NULL;
      if(key < root->data) {
        cout << "less..." << endl;
        deleteNode(root->left, key);
      } else if(key > root->data) {
        cout << "greater..." << endl;
         deleteNode(root->right, key);
      } else {
        if(root->left == NULL && root->right == NULL) {
        root = NULL;
        delete root;
        cout << "Deleted 1" << endl;
      } else if(!root->left) {
        root->data = root->right->data;
         deleteNode(root->right, root->right->data);
        cout << "Deleted 2" << endl;
      } else if(!root->right) {
        root->data = root->left->data;
       deleteNode(root->left, root->left->data);
        cout << "Deleted 3" << endl;
      } else {
       Node* temp = root->left;
       while(temp->right != NULL) {
         temp= temp->right; 
       }
       root->data = temp->data;
       deleteNode(root->left, temp->data);
       delete temp;
        cout << "Deleted 4" << endl;
      }
      }
      return root;
      // nodeToBeDeleted = searchNode(root, key);
      // if(nodeToBeDeleted) cout << "found " << nodeToBeDeleted->data << endl;
      // if(!nodeToBeDeleted) return;
      
    } 

};


int main() {
  BST myBST;
  Node* _root = NULL;
  _root = myBST.insertNode(_root,20); //    10
   myBST.insertNode(_root,10);
   myBST.insertNode(_root,53);
   myBST.insertNode(_root,5);
  myBST.insertNode(_root, 14);   
  myBST.insertNode(_root, 18);   
  myBST.insertNode(_root, 49);
  myBST.insertNode(_root, 63);
  myBST.insertNode(_root, 3);
  myBST.insertNode(_root, 7);
  myBST.insertNode(_root, 6);
  myBST.insertNode(_root, 9);
  // myBST.preOrderTraverse(_root);
  // cout<<endl;
  // myBST.inOrderTraverse(_root);
  // cout<<endl;
  // myBST.postOrderTraverse(_root);
  // cout<<endl;
  myBST.BFS(_root);
  //cout << myBST.searchNode(_root, 10);
  cout << endl;
  // cout << myBST.findMax(_root) <<endl;
  // cout << myBST.findMin(_root) <<endl;
  myBST.deleteNode(_root, 63);
  myBST.BFS(_root);
  myBST.deleteNode(_root, 7);
  myBST.BFS(_root);
   myBST.deleteNode(_root, 14);
  myBST.BFS(_root);
  myBST.deleteNode(_root, 53);
  myBST.BFS(_root);

  return 0;
}