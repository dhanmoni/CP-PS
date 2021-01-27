/*
PROBLEM STATEMENT:
Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc. 
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>
#include <climits>
using namespace std;

int MAX_SIZE = 1000;

class specialStack {
  private:
    stack<int> main_stack, min_stack;
  public:
    specialStack(){
      min_stack.push(INT_MAX);
    }
    void push(int x) {
      if(main_stack.size() >= MAX_SIZE) {
        cout << "Stack Overflow" << endl;
        exit(0);
      } else {
         main_stack.push(x);
      if(x < min_stack.top()) {
        min_stack.push(x);
      }
      }
    }
    int pop() {
      if(main_stack.empty()) {
        cout << "Stack UnderFlow" << endl; 
        exit(0);
      } else {
        if(main_stack.top() == min_stack.top()) {
          int x = main_stack.top();
          main_stack.pop();
          min_stack.pop();
          return x;
        } else {
          int x2 = main_stack.top();
          main_stack.pop();
           return x2;
        }
      }
    }
    bool isEmpty() {
      return main_stack.empty();
    }
    bool isFull() {
      return main_stack.size() >= MAX_SIZE;
    }
    int getMin() {
      if(main_stack.size() < 1) {
        return 0;
      }
      return min_stack.top();
    }
    int top() {
      return main_stack.top();
    }
};

int main() {
  specialStack sp1;
  sp1.push(15);
  sp1.push(33);
  sp1.push(20);
  sp1.push(10);
  cout << sp1.top() <<endl; // 10
  cout << sp1.getMin() << endl; //10
  sp1.pop();
  cout << sp1.top() <<endl; //20
  cout << sp1.getMin() << endl; //15
  return 0;
}