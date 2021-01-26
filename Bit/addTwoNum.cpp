/*
PROBLEM STATEMENT:
Add two numbers without using arithmatice operator;
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int addNum(int x, int y) {
  int carry;
  while(y != 0) {
     carry = x & y;
    x = x ^ y;
    y = carry << 1;
  }
  return x;
}

int main() {
  cout << addNum(10, 5);
  return 0;
}