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

    void inOrderIterative(Node* root) {
      if(!root) return;
      stack<Node *> s; 
      Node* curr = root; 
  
    // while (curr != NULL || s.empty() == false) 
    // { 
    //     /* Reach the left most Node of the 
    //        curr Node */
    //     while (curr !=  NULL) 
    //     { 
    //         /* place pointer to a tree node on 
    //            the stack before traversing 
    //           the node's left subtree */
    //         s.push(curr); 
    //         curr = curr->left; 
    //     } 
  
    //     /* Current must be NULL at this point */
    //     curr = s.top(); 
    //     s.pop(); 
  
    //     cout << curr->data << " "; 
  
    //     /* we have visited the node and its 
    //        left subtree.  Now, it's right 
    //        subtree's turn */
    //     curr = curr->right; 
  
    // } /* end of while */
    //   Node* curr = root;
    //  while(curr->left != NULL) {
    //    st.push(curr);
    //    curr = curr->left;
    //    while(curr != NULL || !st.empty()) {
    //    Node* top = st.top();
    //    st.pop();
    //    cout << top->data << " ";
    //    curr = top->right;   
    //  }
    //  }

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
   //myBST.inOrderTraverse(_root);
  //cout<<endl;
  //cout << myBST.numOfNodes(_root);
  cout<< endl;
  cout << myBST.heightOfBSTItr(_root);
  // myBST.postOrderTraverse(_root);
  // cout<<endl;
  //myBST.inOrderIterative(_root);
 // myBST.getNode(_root);
  //cout << myBST.searchNode(_root, 10);
  cout << endl;
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