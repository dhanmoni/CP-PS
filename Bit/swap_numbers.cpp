/*
PROBLEM STATEMENT:
Swap two numbers without using a temporary opertor;
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>


int main() {
  int a = 10, b= 5;
  std::cout << "BEFORE == " << "\t";
  std::cout << "a = " << a << ", b = " << b << std::endl;

  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  std::cout << "AFTER == " << "\t";
  std::cout << "a = " << a << ", b = " << b << std::endl;

  return 0;
}