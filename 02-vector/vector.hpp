#include <iostream>

class Vector {
 public:
  Vector();
  ~Vector();

  // How many elements are currently stored in the vector
  int Size();
  // Add an element to the end of the vector
  void push_back(int element);
  // Get the element at index ‘index’ from the vector
  // Here, we are overloading the [] operator, so that we can access vector
  //   elements the same way we access elements of an array.
  int &operator[](int index);
  
 private:
  // How many elements are stored in the vector.
  int size;
  // How many elements our current underlying array can store.
  int capacity;
  // Vector data
  int *buffer;
};