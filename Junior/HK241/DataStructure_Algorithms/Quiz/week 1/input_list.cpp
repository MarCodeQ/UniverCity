#include <iostream>
#include <sstream>

using namespace std;
typedef struct Item* ptr;

struct Item

{

    int value;

    ptr next;
};
ptr inputList()
{
  ptr head = NULL;
  int num;
  while (true){
    cin >> num;
    if (num >= 0)
    {
      ptr new_item = new Item;
      new_item->value = num;
      new_item->next = head;
      head = new_item;
    }
    else
    {
      break;
    }
  }
  return head;
}
// Function to print the linked list
void printList(ptr head)
{
  ptr current = head;
  while (current != nullptr)
  {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

int main()
{
  ptr list = inputList();
  printList(list);
  return 0;
}