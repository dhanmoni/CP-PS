/*
Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. Find the missing element.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int MissingNumber(vector<int>& array, int n);

int main() {
  int t;
  cin >> t;
  while(t--) {
   int n;
   cin >> n;
   vector<int> array(n-1);
   for(int i = 0; i < n-1; i++) cin >> array[i];

   cout << MissingNumber(array, n) << "\n";
  }
  return 0;
}

// User function template for C++

int MissingNumber(vector<int>& array, int n) {
    // Your code goes here
    int res;
    for(int i = 1; i <= n; i++) {
        res ^= i;
    }
    for(int j = 0; j < array.size(); j++){
        res ^= array[j];
    }
    return res;
}