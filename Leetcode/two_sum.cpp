/*
PROBLEM-STATEMENT:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
URL:
https://leetcode.com/problems/two-sum/
*/

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> res;
        for(int i = 0; i < nums.size(); i++){
          for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target) {
              res = {i,j};
            }
          }
        }
      return res;
    }
};

int main() {
  
  return 0;
}
