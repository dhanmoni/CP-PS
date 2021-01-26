/*
PROBLEM STATEMENT:
Count the number of ones in a binary representation of a number
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>

int totalSetBinaryBit(int num) {
  int count = 0;
  while(num != 0) {
    num = num & (num -1);
    count++;
  }
  return count;
}

int main() {
  std::cout << totalSetBinaryBit(30);
  return 0;
}