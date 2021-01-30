/*
PROBLEM STATEMENT:
Create a binary search tree with all its methods
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class Node {
  public:
    int data;
    Node *right;
    Node *left;
};

class NodeObj {
  public:
    int dist;
    Node* node;
    NodeObj(int dist, Node* node) {
      this->dist = dist;
      this->node = node;
    }
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

    void inOrderIterative(Node* root) {
      if(!root) return;
      stack<Node *> s; 
      Node* curr = root; 

      while(curr != NULL || s.empty() == false) {
        if(curr != NULL) {
          s.push(curr);
          curr = curr->left;
        } else {
          curr = s.top();
        cout << curr->data << " ";
        s.pop();

        curr = curr->right;
        }
      }
    }

    void postOrderItr(Node* rootNode) {
      if(!rootNode) return;
      stack<Node*> st_temp;
      stack<Node*> st_res;

      Node* curr = rootNode;
      
      while(!st_temp.empty() || curr != NULL) {
        if(curr != NULL) {
          st_temp.push(curr);
          st_res.push(curr);
          curr = curr->right;
        } else {
          curr = st_temp.top();
          st_temp.pop();
          curr = curr->left;
        }
        
      }
      while(!st_res.empty()) {
        cout << st_res.top()->data << " ";
        st_res.pop();
      }
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

    void getVerticalOrderItr( int hd, queue<pair<int, Node*>> &q,
    map<int, vector<int>> &mymap) {
      while(!q.empty()) {
        pair<int, Node*> temp = q.front();
        q.pop();
        hd = temp.first;
        Node* node = temp.second;
        mymap[hd].push_back(node->data);
        if(node->left) q.push(make_pair(hd-1, node->left));
        if(node->right) q.push(make_pair(hd+1, node->right));
      }
    }
    void verticalOrder(Node* rootNode) {
      if(!rootNode) return;

      map<int, vector<int>> mymap;
      queue<pair<int, Node*>> q;
      int hd = 0;
      q.push(make_pair(0, rootNode));
      getVerticalOrderItr(hd, q, mymap);
      map<int, vector<int>>:: iterator it;

      for(it = mymap.begin(); it != mymap.end(); ++it) {
        for(int i = 0; i < it->second.size(); ++i) {
          cout << it->second[i] << "\t";
        }
      }
    }

    void getVertcialOrderRec(Node* rootNode,int hd, map<int, vector<int>> &h_map) {
      if(!rootNode) return;
      h_map[hd].push_back(rootNode->data);
      getVertcialOrderRec(rootNode->left, hd -1, h_map);
      getVertcialOrderRec(rootNode->right, hd +1, h_map);
    }

    void verticalOrderRec(Node* rootNode) {
      if(!rootNode) return;
      int hd = 0;
      map<int, vector<int>> map1;
      getVertcialOrderRec(rootNode, hd, map1);

      map<int, vector<int>> ::iterator it;

      for(it = map1.begin(); it != map1.end(); ++it) {
        for(int i = 0; i < it->second.size(); ++i) {
          cout << it->second[i] << "\t";
        }
      }
    }

    void topView(Node* rootNode) {
      if(!rootNode) return;
      map<int, vector<int>> m;
      queue<pair<int, Node*>> q;
      int hd = 0;
      q.push(make_pair(0, rootNode));
      getVerticalOrderItr(hd,q, m);

      map<int, vector<int>>::iterator it;

      for(it = m.begin(); it != m.end(); ++it) {
        cout << it->second[0] << "\t";
      }
    }

    void bottomView(Node* rootNode) {
      if(!rootNode) return;
      map<int, vector<int>> hm;
      queue<pair<int, Node*>> q;
      int hd = 0;
      q.push(make_pair(0, rootNode));
      getVerticalOrderItr(hd, q, hm);

      map<int, vector<int>> ::iterator it;
      int length;
      for(it = hm.begin(); it != hm.end(); ++it) {
        length = it->second.size();
        cout << it->second[length-1] << "\t";
      }
    }

    void leftView(Node* rootNode) {
      if(!rootNode) return;
      queue<Node*> q;
      queue<int> res;
      q.push(rootNode);
      while(true) {
        int nodeCount = q.size(); 
        if(nodeCount == 0) break;
        res.push(q.front()->data);
        while(nodeCount > 0) {
          Node* temp = q.front();
          q.pop();
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
          nodeCount--;
        }
      }

      while(!res.empty()){
        cout << res.front()<< "\t";
        res.pop();
      }
    }



   void rightView(Node* rootNode) {
     if(!rootNode) return;

     queue<Node*> q;
      q.push(rootNode);
      while(!q.empty()){
        int nodeCount = q.size();
        for(int i = 1; i <= nodeCount; ++i){
          Node* temp = q.front();
          q.pop();
          if(i == nodeCount) {
            cout << temp->data << "\t";
          }
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
        }
      }
   }

  //  void diagonalView(Node* rootNode) {
  //    if(!rootNode) return;
  //    int hd = 0;
  //    map<int, vector<int>> m;
  //    queue<Node*> q;
  //    Node* curr = rootNode;
  //    q.push(curr);
  //    while(!q.empty() || curr != NULL){
  //      if(curr != NULL) {
  //         if(curr->left) q.push(curr->left);
  //         if(curr->right) q.push(curr->right);
  //      }
  //    }
  //  }

  void getDiagonalOrder(Node* rootNode) {
    if(!rootNode) return;
    map<int, vector<int>> m;
    queue<pair<int, Node*>> q;
    Node* curr = rootNode;
    q.push(make_pair(0, curr));

    while(!q.empty()){
      pair<int, Node*> temp = q.front();
      q.pop();
      int dist = temp.first;
      Node* node = temp.second;
      m[dist].push_back(node->data);
      if(node->left) q.push(make_pair(dist+1, node->left));
      if(node->right) q.push(make_pair(dist, node->right));
    }
    map<int, vector<int>> ::iterator it;
    int index;
    for(it = m.begin(), index=1; it != m.end(); ++it, ++index){
      int length = it->second.size();
      cout << index <<"-th diagonal values--";
      for(int i = 0; i <length; ++i) {
        cout << it->second[i] << " ";
      }
      cout<<endl;
    }
  }

  //NOT IN SORTED ORDER:
  void boundaryTraversal(Node* rootNode) {
    if(!rootNode) return;
    queue<Node*> q;
    q.push(rootNode);
    while(!q.empty()){
      int nodeCount = q.size();

      for(int i = 1; i <= nodeCount; ++i){
        Node* temp = q.front();
        q.pop();
        if(i == 1 || i == nodeCount){
          cout << temp->data << " \t";
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
      }
    }
  }

  void printLeafNodes(Node* rootNode){
    if(!rootNode) return;
    if(!rootNode->left && !rootNode->right) {
      cout << rootNode->data << " ";
      return;
    } 
    printLeafNodes(rootNode->left);
    printLeafNodes(rootNode->right);

  }
  void printLeftNodes(Node* rootNode){
    if(!rootNode) return;
    Node* curr = rootNode;
    while(curr->left != NULL) {
      cout << curr->data << " ";
      curr = curr->left;
    }
  }
  void printRightNodes(Node* rootNode){
    if(!rootNode) return;
    stack<int> s;
    Node* curr = rootNode;
    while(curr->right != NULL) {
      s.push(curr->data);
      curr = curr->right;
    }
    while(!s.empty()){
      cout << s.top() << " ";
      s.pop();
    }
  }
  void printRightNodesRec(Node* rootNode){
    if(!rootNode) return;
    if(!rootNode->left && !rootNode->right) return;
    printRightNodesRec(rootNode->right);
    cout << rootNode->data << " ";
  }

  void printLeftNodesRec(Node* rootNode){
    if(!rootNode) return;
    if(!rootNode->left && !rootNode->right) return;
    cout << rootNode->data << " ";
    printLeftNodesRec(rootNode->left);
  }
  
  void getBoundaryNodes(Node* rootNode) {
    if(!rootNode) return;
    printLeftNodes(rootNode);
    printLeafNodes(rootNode);
    printRightNodes(rootNode->right);
  }

    Node* searchNode(Node* rootNode, int key) {
      if(!rootNode) {
        cout << "Empty tree!" << endl;
        return NULL;
      }
      if(key == rootNode->data){
         return rootNode;
         }
      else if(key < rootNode->data) {
        return searchNode(rootNode->left, key);
      } else {
        return searchNode(rootNode->right, key);
      }
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
        deleteNode(root->left, key);
      } else if(key > root->data) {
         deleteNode(root->right, key);
      } else {
        if(root->left == NULL && root->right == NULL) {
        root = NULL;
        delete root;
      } else if(!root->left) {
        root->data = root->right->data;
         deleteNode(root->right, root->right->data);
      } else if(!root->right) {
        root->data = root->left->data;
        deleteNode(root->left, root->left->data);
      } else {
        Node* temp = root->left;
        while(temp->right != NULL) {
          temp= temp->right; 
        }
        root->data = temp->data;
        deleteNode(root->left, temp->data);
        delete temp;
        }
      }
      return root;
    } 

    int numOfNodes(Node* rootNode) {
      if(!rootNode) return 0;
      int count = 0;
      queue<Node*> q;
      Node* curr = rootNode;
      q.push(curr);
      while(!q.empty()){
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        q.pop();
        count++;
      }
      return count;
    }

    int heightOfBST(Node* rootNode) {
      if(!rootNode) return -1;
      return 1 + max(heightOfBST(rootNode->left), heightOfBST(rootNode->right));
    }

    int heightOfBSTItr(Node* rootNode) {
      if(!rootNode) return -1;
      queue<Node*> q;
      q.push(rootNode);
      int height = -1;
      while(true) {
        int nodeCount = q.size();
        if(nodeCount == 0) return height;
        height++;

        while(nodeCount > 0) {
          Node* curr = q.front();
          if(curr->left) q.push(curr->left);
          if(curr->right) q.push(curr->right);
          q.pop();
          nodeCount--;
        }
      }
    }
   
   int numOfLeafNode(Node* rootNode) {
     if(!rootNode) return -1;
     int count = 0;
     queue<Node*> q;
     Node* curr = rootNode;
     q.push(curr);
     while(!q.empty()){
       if(!q.front()->left && !q.front()->right) count++;
       if(q.front()->left) q.push(q.front()->left);
       if(q.front()->right) q.push(q.front()->right);
        q.pop();
     }
     return count;
   }

   bool isLesserSubtree(Node* rootNode, int val){
     if(rootNode == NULL) return true;
     if(rootNode->data < val && isLesserSubtree(rootNode->left, val) && isLesserSubtree(rootNode->right, val)) return true;
     return false;
   }

   bool isGreaterSubtree(Node* rootNode, int val) {
     if(rootNode == NULL) return true;
     if(rootNode->data > val && isGreaterSubtree(rootNode->left, val) && isGreaterSubtree(rootNode->right, val)) return true;
     return false;
   }

   bool checkBST(Node* rootNode) {
     if(!rootNode) return true;
     if(isLesserSubtree(rootNode->left, rootNode->data) && 
     isGreaterSubtree(rootNode->right, rootNode->data) && 
     checkBST(rootNode->left) && 
     checkBST(rootNode->right)) return true;
     return false;
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
   myBST.printLeftNodesRec(_root);
  //  myBST.printRightNodesRec(_root);
  //  myBST.getBoundaryNodes(_root);
  //  myBST.getDiagonalOrder(_root);
  // myBST.boundaryTraversal(_root);
  // myBST.rightView(_root);
  // Node* searched = myBST.searchNode(_root, 5);
  // cout << "left val = "<< searched->data;
 // myBST.preOrderTraverse(_root);
  // cout<<endl;
  //  myBST.inOrderTraverse(_root);
  //cout<<endl;
  //cout << myBST.numOfNodes(_root);
  // cout<< endl;
  // cout << myBST.checkBST(_root);
  // myBST.postOrderTraverse(_root);
  // cout<<endl;
  //myBST.inOrderIterative(_root);
 // myBST.getNode(_root);
  //cout << myBST.searchNode(_root, 10);
  // cout << endl;
  //myBST.inOrderIterative(_root);

  // cout << myBST.findMax(_root) <<endl;
  // cout << myBST.findMin(_root) <<endl;
  // myBST.deleteNode(_root, 63);
   //myBST.BFS(_root);
  // myBST.deleteNode(_root, 7);
  // myBST.BFS(_root);
  //  myBST.deleteNode(_root, 14);
  // myBST.BFS(_root);
  // myBST.deleteNode(_root, 53);
  // myBST.BFS(_root);

  return 0;
}