// heap.hpp
#ifndef HEAP_HPP
#define HEAP_HPP

#include "../../main.hpp"

class Heap {
  int MAX_SIZE = 1000;

 public:
  Heap();
  int allocation(int size);
  void deallocation(int address, int size);
  ~Heap();

 private:
  class Node {
   public:
    int address;
    int size;
    Node* next;

   public:
    Node(int address, int size, Node* next = nullptr) {
      this->address = address;
      this->size = size;
      this->next = next;
    }
  };

 protected:
  Node* free_memory;
};

#endif  // HEAP_HPP