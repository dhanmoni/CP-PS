/*
PROBLEM STATEMENT:
Invert a binary tree
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
      cout << x << endl;
      this->data = x;
      this->left = NULL;
      this->right = NULL;
    }
};

class BT {
  private:
    Node* root;
    void insert(Node* rootNode,int key) {
      if(rootNode == NULL) {
        cout << "creating new node="<< endl;
        Node* newNode = new Node(key);
        root = newNode;
        return;
      } 
      if(key < rootNode->data) {
        if(rootNode->left == NULL) {
          rootNode->left = new Node(key);
          return;
        }
        insert(rootNode->left, key);
      } else {
        if(rootNode->right == NULL) {
          rootNode->right = new Node(key);
          return;
        }
        insert(rootNode->right, key);
      }
    }
    void bfsPvt(Node* rootNode) {
      if(!rootNode) return;
      queue<Node*> q;
      q.push(rootNode);
      while(!q.empty()) {
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        cout << q.front()->data <<" ";
        q.pop(); 
      }
    }
    Node* invertBTPvt(Node* rootNode) {
      if(!rootNode) return NULL;
      Node* left = invertBTPvt(rootNode->left);
      Node* right = invertBTPvt(rootNode->right);

      rootNode->left = right;
      rootNode->right =left;
      return rootNode;
    }
  public:
    BT() {
      root = NULL;
    }
    void insertNode(int key) {
      insert(root, key);
    }
    void BFS() {
      bfsPvt(root);
    }
    void invertBT() {
      invertBTPvt(root);
    }
};

int main() {
  BT myBT;
  myBT.insertNode(10);
  myBT.insertNode(30);
  myBT.insertNode(7);
  myBT.insertNode(9);
  myBT.insertNode(3);
  myBT.insertNode(22);
  myBT.insertNode(35);
  myBT.BFS();
  myBT.invertBT();
  cout<<endl;
  myBT.BFS();
  return 0;
}