#include "declaration.hpp"

// TODO implement

string ListDelarations::str() const {
  if (this->size == 0) return "[]";
  string result = "";
  for (int i = 0; i < this->size - 1; i++) {
    result += this->listDelarations[i]->str() + "\n\t";
  }
  return "[\n\t" + result + this->listDelarations[this->size - 1]->str() +
         "\n]";
}