/*
PROBLEM STATEMENT:

URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetOfSet(vector<int> mySet) {
  int n = mySet.size();
  for(int i = 0; i < (1 << n); i++) {
    for(int j = 0; j < n; j++) {
      if( i & (1<<j)) {
        cout << mySet[j] << " ";
      }
    } cout << endl;
  }
}

int main() {
  vector<int> arr = {1,2,3};
  subsetOfSet(arr);
  return 0;
}