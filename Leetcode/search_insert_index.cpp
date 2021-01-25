/*
Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
https://leetcode.com/problems/search-insert-position/
*/
#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {  
        int index = 0;
        vector<int>::iterator output;
        output = lower_bound(nums.begin(), nums.end(), target);
        index = output - nums.begin();
        return index;
    }
};

int main() {
  
  return 0;
}