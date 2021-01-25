/*
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

https://leetcode.com/problems/plus-one/
*/

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
        
          for(int i = n-1; i >= 0; i--){
             if(digits[i] < 9) {
                digits[i] += 1;
               break;
              }else {
                digits[i] = 0; 
             }
          }
      if(digits[0] == 0) {
              digits[0] = 1;
            digits.emplace_back(0);
            }
        
      return digits;
    }
};

int main() {
  
  return 0;
}