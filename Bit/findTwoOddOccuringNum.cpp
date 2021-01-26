/*
PROBLEM STATEMENT:
Given an unsorted array that contains even number of occurrences for all numbers except two numbers. Find the two numbers which have odd occurrences in O(n) time complexity and O(1) extra space.
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void findTwoOddNum(vector<int> arr) {
  int xor_val;
  int set_bit_no = 0;
  int size = arr.size();
  int x = 0, y = 0;
  for(int i = 0; i < size; i++) {
    xor_val ^= arr[i];
  }

  set_bit_no = xor_val & ~(xor_val - 1);

  for(int i = 0; i < size; i++) {
    if(arr[i] & set_bit_no) {
      x = x ^ arr[i];
    } else {
      y = y ^ arr[i];
    }
  }

  cout << "the 2 numbers are = " << x << ", " << y << endl;
}

int main() {
  vector<int> arr = {2, 4, 5, 3, 2,3, 6, 6};
  findTwoOddNum(arr);
  return 0;
}