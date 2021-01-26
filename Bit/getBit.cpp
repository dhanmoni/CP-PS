/*
PROBLEM STATEMENT:

URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>

// 1010
//  1 << 3
//  1000
//  1010 & 1000 = 1000 
//  

int getBit(int num, int pos) {
  return ((num & (1 << pos)) != 0);
}

int setBit(int num, int pos) {
  return num | (1 << pos);
}
int clearBit(int num, int pos) {
  return (num & (~(1 << pos)));
}

int reverseBit(int num, int pos) {
  return (num & ( ~(1<< pos)));
}

int main() {
  // std::cout << getBit(26, 3) << std::endl;
  // std::cout << setBit(26, 2) << std::endl;
  // std::cout << clearBit(4, 2) << std::endl;
  std::cout << reverseBit(4,2) << std::endl;
  return 0;
}