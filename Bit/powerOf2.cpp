/*
PROBLEM STATEMENT:
Check if a number is power of 2 or not;
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPowerOfTwo (int n) {
  return n && !(n & n-1);
}

int main() {
  cout << isPowerOfTwo(7) << endl;
  cout << isPowerOfTwo(15) << endl;;
  cout << isPowerOfTwo(16) << endl;;
  return 0;
}