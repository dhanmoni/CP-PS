/*
Given a set of numbers where all elements occur even number of times except one number, find the odd occurring number
*/

#include<iostream>
#include<vector>
#include<algorithm>

int findOdd(std::vector<int> v) {
   int res = 0; 
    for (int i = 0; i < v.size(); i++) 
        res ^= v[i]; 
    return res; 
}

int main() {
  std::vector<int> myVec = {12, 12, 15, 15, 4, 56, 56};
  std::cout << "The number is " << findOdd(myVec) << std::endl;
  return 0;
}