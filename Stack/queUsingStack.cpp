/*
PROBLEM STATEMENT:
Construct a queue using stack!
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

class queue {
  stack<int> s1, s2;
  public:
  void enQueue(int num) {
    s1.push(num);
    cout << num << " enqueued to the queue!" <<endl;
  }

  int deQueue() {
    if(s1.empty()) {
      cout << "No element in the queue!";
      return -1;
    } else {
      while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      int x = s2.top();
      s2.pop();
      while(!s2.empty()) {
        int popped = s2.top();
        s1.push(popped);
        s2.pop();
      }
      return x;
    }
  }
};
int main() {
  queue q1;
  q1.enQueue(10);
  q1.enQueue(30);
  cout << "deleted " << q1.deQueue() <<endl;;
  q1.enQueue(40);
  cout << "deleted " << q1.deQueue() <<endl;;
  q1.enQueue(20);
  cout << "deleted " << q1.deQueue() <<endl;;

  return 0;
}