#include "Sorting.h"

/*
  Please refer to sorting.h for documentation on each function.

   + ------ N O T E: -- Big scary warning! -----------------------------\
   |                                                                    |
   |    We clearly can't use unit testing to ensure that you're         |
   |    actually implementing the correct algorithm. I suppose we could |
   |    write some complicated static analysis checker. But it is       |
   |    easier to just look at it with our eyeballs.                    |
   |                                                                    |
   |    After the assignment is due, we will look at the most recent    |
   |    version of your implementation that got the highest score and   |
   |    make sure you're not doing something sneaky like using a        |
   |    standard library call to sort a vector.                         |
   |                                                                    |
   |    Anyone caught doing this (even though it is kinda funny) will   |
   |    be given 0 points on the assignment.                            |
   |                                                                    |
   `--------------------------------------------------------------------/ 
*/

// constructor, initialize class variables and pointers here if you need.
Sorting::Sorting(){
  // Your code here
}

//deconstructor,
Sorting::~Sorting(){
}

void Sorting::quicksort(vector<int>& data, int low_idx, int high_idx){

  // Base case: If the partition size is 1 or zero 
  // elements, then the partition is already sorted
  if (low_idx >= high_idx) {
    return;
  }
   
  // Partition the data within the array. Value lowEndIndex 
  // returned from partitioning is the index of the low 
  // partition's last element.
  int lowEndIndex = quicksort_partition(data, low_idx, high_idx);
   
  // Recursively sort low partition (low_idx to lowEndIndex) 
  // and high partition (lowEndIndex + 1 to high_idx)
  quicksort(data, low_idx, lowEndIndex);
  quicksort(data, lowEndIndex + 1, high_idx);

}

int Sorting::quicksort_partition(vector<int>& data, int low_idx, int high_idx){
  
  // Pick middle element as pivot
  int midpoint = low_idx + (high_idx - low_idx) / 2;
  int pivot = data[midpoint];
   
  bool done = false;
  while (!done) {
    // Increment low_idx while data[low_idx] < pivot
    while (data[low_idx] < pivot) {
      low_idx += 1;
    }
      
    // Decrement high_idx while pivot < data[high_idx]
    while (pivot < data[high_idx]) {
      high_idx -= 1;
    }
      
    // If zero or one elements remain, then all data are 
    // partitioned. Return high_idx.
    if(low_idx >= high_idx) {
      done = true;
    }
    else {
      // Swap data[low_idx] and data[high_idx]
      int temp = data[low_idx];
      data[low_idx] = data[high_idx];
      data[high_idx] = temp;
         
      // Update low_idx and high_idx
      low_idx += 1;
      high_idx -= 1;
    }
  }
   
  return high_idx;

}

void Sorting::bubblesort(vector<int>& data){
  int numbersSize = data.size();
  for (int i = 0; i < numbersSize - 1; i++) {
      for (int j = 0; j < numbersSize - i - 1; j++) {
        if (data[j] > data[j+1]) {
          int temp = data[j];
          data[j] = data[j + 1];
          data[j + 1] = temp;
        }
      }
  }
}


void Sorting::mergesort(vector<int>& data){
  if (data.size() <= 1) {
    return; // Base case: already sorted or empty vector
  }

  // Divide the data into two halves
  int mid = data.size() / 2;
  vector<int> left(data.begin(), data.begin() + mid);
  vector<int> right(data.begin() + mid, data.end());

  // Recursively sort the left and right halves
  mergesort(left);
  mergesort(right);

  // Merge the sorted halves
  merge(left, right, data);
}

void Sorting::merge(vector<int>& left, vector<int>& right, vector<int>& result){
    result.clear(); // Clear the result vector before merging
  
  // Merge the contents of left and right vectors into the result vector
  int leftIndex = 0;
  int rightIndex = 0;

  while (leftIndex < left.size() && rightIndex < right.size()) {
    if (left[leftIndex] <= right[rightIndex]) {
      result.push_back(left[leftIndex]);
      leftIndex++;
    } else {
      result.push_back(right[rightIndex]);
      rightIndex++;
    }
  }

  // Copy any remaining elements from the left vector
  while (leftIndex < left.size()) {
    result.push_back(left[leftIndex]);
    leftIndex++;
  }

  // Copy any remaining elements from the right vector
  while (rightIndex < right.size()) {
    result.push_back(right[rightIndex]);
    rightIndex++;
  }
}

void Sorting::mystery_sort(vector<int>& data){
  //Selection Sort
  int dataSize = data.size();
  int i = 0;
  int j = 0;
  int indexSmallest = 0;
  int temp = 0;  // Temporary variable for swap
   
  for (i = 0; i < dataSize - 1; ++i) {
      
    // Find index of smallest remaining element
    indexSmallest = i;
    for (j = i + 1; j < dataSize; ++j) {
         
      if ( data[j] < data[indexSmallest] ) {
        indexSmallest = j;
      }
    }
      
    // Swap numbers[i] and numbers[indexSmallest]
    temp = data[i];
    data[i] = data[indexSmallest];
    data[indexSmallest] = temp;
   }
}