#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Student
{
private:
  string name;
  int score;

public:
  // Constructor
  Student(const string &newName, int newScore) : name(newName), score(newScore) {}

  // Destructor
  ~Student() {}

  // Accessor functions
  string getName() const { return name; }
  int getScore() const { return score; }
};

void addStudent(Student **&studentList, int &numStudents)
{
  string name;
  int score;

  cout << "Enter student name: ";
  cin >> name;
  cout << "Enter student score: ";
  cin >> score;

  Student *newStudent = new Student(name, score);

  // Resize the array and add the new student
  Student **temp = new Student *[numStudents + 1];
  for (int i = 0; i < numStudents; ++i)
  {
    temp[i] = studentList[i];
  }
  temp[numStudents] = newStudent;

  delete[] studentList;
  studentList = temp;
  numStudents++;
}

void displayStudents(const Student **studentList, int numStudents)
{
  cout << "List of Students:\n";
  for (int i = 0; i < numStudents; ++i)
  {
    cout << studentList[i]->getName() << ": " << studentList[i]->getScore() << endl;
  }
}

void displayBestStudents(const Student **studentList, int numStudents)
{
  int highestScore = 0;

  // Find the highest score
  for (int i = 0; i < numStudents; ++i)
  {
    if (studentList[i]->getScore() > highestScore)
    {
      highestScore = studentList[i]->getScore();
    }
  }

  // Display students with the highest score
  cout << "Best Student(s) with Highest Score (" << highestScore << "):\n";
  for (int i = 0; i < numStudents; ++i)
  {
    if (studentList[i]->getScore() == highestScore)
    {
      cout << studentList[i]->getName() << ": " << studentList[i]->getScore() << endl;
    }
  }
}

void removeStudent(Student **&studentList, int &numStudents, const string &nameToRemove)
{
  for (int i = 0; i < numStudents; ++i)
  {
    if (studentList[i]->getName() == nameToRemove)
    {
      delete studentList[i];
      for (int j = i; j < numStudents - 1; ++j)
      {
        studentList[j] = studentList[j + 1];
      }
      studentList[numStudents - 1] = nullptr;
      numStudents--;
      break;
    }
  }
}
int readChoice()
{
  int choice;
  cout << "\nStudent Management System\n";
  cout << "1. Add Student\n";
  cout << "2. Display Students\n";
  cout << "3. Display Best Student(s)\n";
  cout << "4. Remove Student\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}
int main()
{
  Student **studentList = nullptr;
  int numStudents = 0;
  int choice = 0;
  do
  {
    choice = readChoice();
    switch (choice)
    {
    case 1:
      addStudent(studentList, numStudents);
      break;
    case 2:
      displayStudents((const Student **)studentList, numStudents);
      break;
    case 3:
      displayBestStudents((const Student **)studentList, numStudents);
      break;
    case 4:
    {
      string nameToRemove;
      cout << "Enter student name to remove: ";
      cin >> nameToRemove;
      removeStudent(studentList, numStudents, nameToRemove);
    }
    break;
    case 0:
      for (int i = 0; i < numStudents; ++i)
      {
        delete studentList[i];
      }
      delete[] studentList;
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);

  return 0;
}
