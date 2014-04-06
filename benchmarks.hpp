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

// Benching for insert from top.
microseconds insert_deque(int numberOfInput);
microseconds insert_list(int numberOfInput);
microseconds insert_stack(int numberOfInput);

// Benching for sort.
microseconds sort_deque(int numberOfInput);
microseconds sort_list(int numberOfInput);

// Benching for destruction.
microseconds destruction_deque(int numberOfInput);
microseconds destruction_list(int numberOfInput);
microseconds destruction_stack(int numberOfInput);

// Benching for getting top elements and delete.
microseconds top_deque(int numberOfInput);
microseconds top_list(int numberOfInput);
microseconds top_stack(int numberOfInput);


/************************************************************************/


/************************* Main Functions ******************************/

// benching_insert
// int numberOfInput - The number of data that will be inserted into the data structures.
// Instantiates tests for inserts of the data strucutres.
// List will have data pushed from the front
// Stack will have data inserted by push.
// Deqye will have data be inserted by pushing from the front.
void benching_structures(int numberOfInput){

  // Output the number N to the console.
  std::cout << "The number of inputs, n, for this benchmark is " << numberOfInput << std::endl;

  // Initialize the variables to hold the total time of inserts for data structures.
  microseconds results_insert_deque (0);
  microseconds results_insert_list (0);
  microseconds results_insert_stack (0);
  microseconds results_sort_deque (0);
  microseconds results_sort_list (0);
  microseconds results_distruct_deque (0);
  microseconds results_distruct_list (0);
  microseconds results_distruct_stack (0);

  // Iterate through the number of repetitions and call the insert functions at each.
  for (std::size_t i = 0; i < REP; i++){
  	// Calculate the time it takes for each data structure inserts.
  	// Add up time for each data strucutre specifically.
  	
  	// Deque inserts.
  	results_insert_deque += insert_deque(numberOfInput);

  	// List inserts.
  	results_insert_list += insert_list(numberOfInput);

  	// Stack inserts.
  	results_insert_stack += insert_stack(numberOfInput);

    // Deque sort.
    results_sort_deque += sort_deque(numberOfInput);

    // List sort.
    results_sort_list += sort_list(numberOfInput);

    // Deque destruct.
    results_distruct_deque += destruction_deque(numberOfInput);

    // List destruct.
    results_distruct_list += destruction_list(numberOfInput);
    
    // Stack destruct.
    results_distruct_stack += destruction_stack(numberOfInput);

  }
  // Output the average of the inserts depending on the number of repetitions set.
  std::cout << "Deque insert from front: " << results_insert_deque.count()/REP << std::endl;

  std::cout << "List insert from front: " << results_insert_list.count()/REP << std::endl;

  std::cout << "Stack inserts: " << results_insert_stack.count()/REP << std::endl;

  std::cout << "Deque sort: " << results_sort_deque.count()/REP << std::endl;
  
  std::cout << "List sort: " << results_sort_list.count()/REP << std::endl;

  std::cout << "Deque destruction: " << results_distruct_deque.count()/REP << std::endl;

  std::cout << "List destruction: " << results_distruct_list.count()/REP << std::endl;

  std::cout << "Stack destruction: " << results_distruct_stack.count()/REP << std::endl;
}

/************************************************************************/


/****************************** Insert ********************************/

// insert_deque
// int numberOfInput - The number of data that will be inserted into the deque.
// Insert function for deque. Data will be inserted via push to the back.
// Returns the time elapsed in microseconds
microseconds insert_deque(int numberOfInput){

  // Initialize the deque.
  std::deque<triv> trivial_deque;

  // Push j into front of deque up to the given number of input and time it.
  // Data being pushed will be of the strucutre triv with size_t as an attribute..
  auto start = std::chrono::system_clock::now();
  for (std::size_t j = 0; j < numberOfInput; j++){
  	triv triv_data;
  	triv_data.x = j;	
    trivial_deque.push_front(triv_data);
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
  // Data being pushed to the front of the list will be of triv with size_t as an attribute.
  auto start = std::chrono::system_clock::now();
  for (std::size_t j = 0; j < numberOfInput; j++){
  	triv triv_data;
  	triv_data.x = j;	
    trivial_list.push_front(triv_data);
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


/****************************** Sort **********************************/
// sort_deque
// int numberOfInput - Number of data in the deque.
// Sorts the given data in the deque and return time elapsed in microseconds.
// Fake random data will be pushed from the back.
microseconds sort_deque(int numberOfInput){
  //Instatiate trivial deque with random data.
  std::deque<triv> triv_deque;
  for (std::size_t j = 0; j < numberOfInput; j++){
    triv triv_data;
    triv_data.x = rand()%numberOfInput;    
    triv_deque.push_back(triv_data);
  }

  // Sort the data using std::sort and time it
  auto start = std::chrono::system_clock::now();
  std::sort(std::begin(triv_deque), std::end(triv_deque));
  auto end = std::chrono::system_clock::now();

  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);

  return elapsed;

}

// sort_list
// int numberOfInput - Number of data in the list.
// Sorts the given data in the list and returns time in microseconds.
// Fake random data will be pushed from the back of the list.
microseconds sort_list(int numberOfInput){
  //Instantiate trivial list with random data.
  std::list<triv> triv_list;
  for(std::size_t j =0; j < numberOfInput; j++){
    triv triv_data;
    triv_data.x = rand()%numberOfInput;
    triv_list.push_back(triv_data);
  }

  // Sort using the given containers sort function and time it.
  auto start = std::chrono::system_clock::now();
  triv_list.sort();
  auto end = std::chrono::system_clock::now();

  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);

  return elapsed;

}



/************************************************************************/

/******************************** Destruction ********************************/
// destruction_deque
// int numberOfInput - number of data that needs to be deleted
// Calculates time it takes to fully delete the deque given the number of input.
// Returns the time in microseconds.
microseconds destruction_deque(int numberOfInput){
  // Instantiate deque with random data.
  std::deque<triv> triv_deque;
  for (std::size_t j = 0; j < numberOfInput; j++){
    triv triv_data;
    triv_data.x = rand()%numberOfInput;    
    triv_deque.push_back(triv_data);
  }

  //Record time of clearing the deque using the given container function.
  auto start = std::chrono::system_clock::now();
  triv_deque.clear();
  auto end = std::chrono::system_clock::now();

  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);

  return elapsed;


}

// destruction_list
// int numberOfInput - number of data that needs to be deleted
// Calculates time it takes to fully delete the list given the number of input.
// Returns the time in microseconds.
microseconds destruction_list(int numberOfInput){

  //Instantiate trivial list with random data.
  std::list<triv> triv_list;
  for(std::size_t j =0; j < numberOfInput; j++){
    triv triv_data;
    triv_data.x = rand()%numberOfInput;
    triv_list.push_back(triv_data);
  }

  // Delete using the given containers sort function and time it.
  auto start = std::chrono::system_clock::now();
  triv_list.clear();
  auto end = std::chrono::system_clock::now();

  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);

  return elapsed;



}

// destruction_stack
// int numberOfInput - number of data that needs to be deleted
// Calculates time it takes to fully delete the stack given the number of input.
// Returns the time in microseconds.
microseconds destruction_stack(int numberOfInput){

  // Instantiate stack with random data.
  std::stack<triv> triv_stack;
  for (std::size_t j = 0; j < numberOfInput; j++){
    triv triv_data;
    triv_data.x = rand()%numberOfInput;    
    triv_stack.push(triv_data);
  }

  // Pop till empty and time it.
  auto start = std::chrono::system_clock::now();
  while ( ! triv_stack.empty() ){
      triv_stack.pop();
  }
  auto end = std::chrono::system_clock::now();

  microseconds elapsed = std::chrono::duration_cast<microseconds>(end - start);

  return elapsed;
}



/************************************************************************/

/******************************** Top k elements********************************/
// microseconds top_deque(int numberOfInput);
// microseconds top_list(int numberOfInput);
// microseconds top_stack(int numberOfInput);

/************************************************************************/