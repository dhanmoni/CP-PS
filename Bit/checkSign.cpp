/*
PROBLEM STATEMENT:

URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkSign(int x, int y) {
  return ((x ^ y) < 0);

}

int main() {
  cout << checkSign(-10, 100) <<endl;
  cout << checkSign(310, -100) <<endl;
  cout << checkSign(10, 10) <<endl;
  cout << checkSign(-10, -40) <<endl;
  return 0;
}