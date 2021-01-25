/*
PROBLEM-STATEMENT:
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.URL:
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size() == 0) return 0;
      int i = 0;
      for(int j = 1; j < nums.size(); j++) {
        if(nums[j] != nums[i]) {
          i++;
          nums[i] = nums[j];
        }
      }
      return i + 1;
    }
};

int main() {
  
  return 0;
}