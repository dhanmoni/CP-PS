/*
PROBLEM STATEMENT:
//Given two numbers ‘a’ and b’. 
//Write a program to count number of bits needed to be flipped to convert ‘a’ to ‘b’.
URL:

1010100 -> 1101100 == 3
1101    -> 1000 ==2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int flipCount(int a, int b) {
    int xor_res = a ^ b;
    int count = 0;
    while( xor_res != 0) {
      xor_res = (xor_res & (xor_res -1));
      count++;
    }
    return count;
}

int main() {
  cout << flipCount(100, 120);
  return 0;
}