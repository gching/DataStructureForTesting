// benchmarks.hpp
// Definitions and Functions assisting in benchmarking of data strcutures
// Gavin Ching
// March 30, 2014

#include <chrono>
#include <stack>
#include <deque>
#include <list>
#include <iostream>
#include <random>


//  Chrono typedefs
typedef std::chrono::microseconds microseconds;

// Number of repetions in each test
static const std::size_t REP = 10;

/************************ Struct Defintiion ******************************/
struct triv {
  std::size_t x;
  bool operator<(const triv &other) const { return x < other.x; }
};

/************************************************************************/

/************************ Function Declarations **************************/
// Main benching function for inserting
void benching_insert(int numberOfInput);

// Benching for deque insert.
microseconds insert_deque(int numberOfInput);

// Benching for list insert.
microseconds insert_list(int numberOfInput);

// Benching for stack insert.
microseconds insert_stack(int numberOfInput);





/************************************************************************/


/*************************Function Descriptions ******************************/

// benching_insert
// int numberOfInput - The number of data that will be inserted into the data structures.
// Instantiates tests for inserts of the data strucutres.
// List will have data pushed from the back.
// Stack will have data inserted by push.
// Deqye will have data be inserted by pushing from the back.
void benching_structures(int numberOfInput){

  // Initialize the variables to hold the total time of inserts for data structures.
  microseconds results_deque (0);
  microseconds results_list (0);
  microseconds results_stack (0);

  // Iterate through the number of repetitions and call the insert functions at each.
  for (std::size_t i = 0; i < REP; i++){
  	// Calculate the time it takes for each data strucutre inserts.
  	// Add up time for each data strucutre specifically.
  	
  	// Queue inserts.
  	results_deque += insert_deque(numberOfInput);

  	// List inserts.
  	results_list += insert_list(numberOfInput);

  	// Stack inserts.
  	results_stack += insert_stack(numberOfInput);
  }
  // Output the average of the inserts depending on the number of repetitions set.
  std::cout << "Deque insert: " << results_deque.count()/REP << std::endl;

  std::cout << "List insert from back: " << results_list.count()/REP << std::endl;

  std::cout << "Stack inserts: " << results_stack.count()/REP << std::endl;

}

// insert_deque
// int numberOfInput - The number of data that will be inserted into the deque.
// Insert function for deque. Data will be inserted via push to the back.
// Returns the time elapsed in microseconds
microseconds insert_deque(int numberOfInput){

  // Initialize the deque.
  std::deque<triv> trivial_deque;

  // Push j into back of deque up to the given number of input and time it.
  // Data being pushed will be of the strucutre triv with size_t as an attribute..
  auto start = std::chrono::system_clock::now();
  for (std::size_t j = 0; j < numberOfInput; j++){
  	triv triv_data;
  	triv_data.x = j;	
    trivial_deque.push_back(triv_data);
  }
  auto end = std::chrono::system_clock::now();
  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);
  return elapsed;
}

// insert_list
// int numberOfInput - The number of data that will be inserted into the list.
// Insert function for list. Data will be pushed at the back of the list.
// Returns the time elapsed in microseconds.
microseconds insert_list(int numberOfInput){

  // Initialize the list
  std::list<triv> trivial_list;

  // Push j into list up to the given number of input and time it.
  // Data being pushed to the back of the list will be of triv with size_t as an attribute.
  auto start = std::chrono::system_clock::now();
  for (std::size_t j = 0; j < numberOfInput; j++){
  	triv triv_data;
  	triv_data.x = j;	
    trivial_list.push_back(triv_data);
  }
  auto end = std::chrono::system_clock::now();
  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);
  return elapsed;

}

// insert_stack
// int numberOfInput - The number of data that will be inserted into the list.
// Insert function for stack. Data will be pushed onto it.
// Returns the time elapsed in microseconds.
microseconds insert_stack(int numberOfInput){
  
  // Initialize the stack.
  std::stack<triv> trivial_stack;

  // Push j onto stack to the given number of input and time it.
  // Data being pushed onto stack will be of triv with size_t as an attribute.
  auto start = std::chrono::system_clock::now();
  for (std::size_t j = 0; j < numberOfInput; j++){
    triv triv_data;
    triv_data.x = j;  	
    trivial_stack.push(triv_data);
  }
  auto end = std::chrono::system_clock::now();
  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);
  return elapsed;


}

/************************************************************************/