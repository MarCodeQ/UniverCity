#include <iostream>
#include <string>
using namespace std;
void storeName(string *students, int index, const string &name)
{
  students[index] = name;
}
void displayNames(const string *studentlist, int count)
{
  for (int i = 0; i < count - 1; ++i)
  {
    cout << studentlist[i] << ", ";
  }
  cout << studentlist[count - 1] << ".\n\n";
}
void removeName(string *students, int &count, const string &name)
{
  for (int i = 0; i < count; ++i)
  {
    if (students[i] == name)
    {
      for (int j = i; j < count - 1; ++j)
      {
        students[j] = students[j + 1];
      }
      --count;
      return;
    }
  }
  cout << "Student not found" << endl;
}

int readChoice()
{
  int choice;
  cout << "Enter 0 to quit" << endl;
  cout << "Enter 1 to add a student" << endl;
  cout << "Enter 2 to display all students" << endl;
  cout << "Enter 3 to remove a student" << endl;
  cin >> choice;
  return choice;
}

int main()
{
  string students[100];
  int last = 0;
  string *studentlist = students;
  string newName;
  int choice = 0;
  do
  {
    switch (choice)
    {
    case 0:
      cout << "Exiting..." << endl;
      break;
    case 1:
      cout << "Enter the name of the student to add: ";
      cin >> newName;
      storeName(studentlist, last, newName);
      last++;
      break;
    case 2:
      cout << "The students are: " << endl;
      displayNames(studentlist, last);
      break;
    case 3:
      cout << "Enter the name of the student to remove: ";
      cin >> newName;
      removeName(studentlist, last, newName);
      break;
    default:
      cout << "Invalid choice. Try again" << endl;
    }
  } while (choice != 0);
  return 0;
}