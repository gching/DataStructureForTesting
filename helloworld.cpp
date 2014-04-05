// Gavin Ching
// helloworld.cpp
// April 5, 2014
// Used to retest my c++ abilities

#include <iostream>
#include <string>
using namespace std;

int main(){

  auto start = std::chrono::system_clock::now();
  cout << "Hello World" << endl;
  auto end = std::chrono::system_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  cout << elapsed.count() << " microseconds" <<'\n';
  return 0;



}