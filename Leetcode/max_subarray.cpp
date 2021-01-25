
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 https://leetcode.com/problems/maximum-subarray/
*/

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      if(nums.size() == 1) return nums[0];
      int sum = 0;
      int max_sum = INT_MIN;
      for(int i =0; i < nums.size(); i++){
        sum += nums[i];
        if(sum >= max_sum ) max_sum = sum;
        if(sum < 0) sum = 0;
      }
      return max_sum;
    }
};

int main() {
  
  return 0;
}