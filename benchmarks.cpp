// benchmarks.cpp
// Used to benchmark specific data structures. Currently benches lists, stack, and queue.
// Gavin Ching
// March 30, 2014

#include "benchmarks.hpp"

int main(){
	// Tests # of n data from the interval of 100000 to 1000000
	for (int n = 100000; n <= 1000000; n=n+100000){
	  benching_structures(n);
	}
	
	return 0;
}