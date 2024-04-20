#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class StudentManager
{
private:
  vector<string> students;

  StudentManager() {}

public:
  static StudentManager &getInstance()
  {
    static StudentManager instance;
    return instance;
  }

  void storeName(const string &name)
  {
    students.push_back(name);
  }

  void displayNames() const
  {
    for (const auto &student : students)
    {
      cout << student << ", ";
    }
    cout << endl
         << endl;
  }

  void removeName(const string &name)
  {
    auto it = find(students.begin(), students.end(), name);
    if (it != students.end())
    {
      students.erase(it);
    }
    else
    {
      cout << "Student not found" << endl;
    }
  }

  const vector<string> &getStudents() const
  {
    return students;
  }
};

int readChoice()
{
  int choice;
  cout << "\nStudent Management System\n";
  cout << "0. Exit\n";
  cout << "1. Add Student\n";
  cout << "2. Display Students\n";
  cout << "3. Remove a student\n";
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main()
{
  string newName;
  int choice = 0;
  StudentManager &studentManager = StudentManager::getInstance();

  do
  {
    choice = readChoice();
    switch (choice)
    {
    case 0:
      cout << "Exiting..." << endl;
      break;
    case 1:
      cout << "Enter the name of the student to add: ";
      cin >> newName;
      studentManager.storeName(newName);
      break;
    case 2:
      cout << "The students are: " << endl;
      studentManager.displayNames();
      break;
    case 3:
      cout << "Enter the name of the student to remove: ";
      cin >> newName;
      studentManager.removeName(newName);
      break;
    default:
      cout << "Invalid choice. Try again" << endl;
    }
  } while (choice != 0);

  return 0;
}
