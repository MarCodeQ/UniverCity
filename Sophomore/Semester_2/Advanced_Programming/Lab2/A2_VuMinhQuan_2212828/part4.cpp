#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Student
{
public:
  Student(const string &name, int score) : name(name), score(score) {}
  ~Student() {}

  string getName() const { return name; }
  int getScore() const { return score; }

private:
  string name;
  int score;
};
class University
{
public:
  University(const string &name) : name(name) {}

  void addStudent(const string &name, int score)
  {
    students.push_back(Student(name, score));
  }

  void displayStudents() const
  {
    for (const auto &student : students)
    {
      cout << "Name: " << student.getName() << ", Score: " << student.getScore() << endl;
    }
  }

  void displayBestStudents() const
  {
    int maxScore = 0;
    for (const auto &student : students)
    {
      if (student.getScore() > maxScore)
      {
        maxScore = student.getScore();
      }
    }

    for (const auto &student : students)
    {
      if (student.getScore() == maxScore)
      {
        cout << "Name: " << student.getName() << ", Score: " << student.getScore() << endl;
      }
    }
  }

  void removeStudent(const string &name)
  {
    students.erase(remove_if(students.begin(), students.end(),
                             [&](const Student &student)
                             { return student.getName() == name; }),
                   students.end());
  }

private:
  string name;
  vector<Student> students;
};
int readChoice()
{
  int choice;
  cout << "\nStudent Management System\n";
  cout << "1. Add Student\n";
  cout << "2. Display Students\n";
  cout << "3. Display Best Student(s)\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}
int main()
{
  University university("My University");
  int choice = 0;
  do
  {
    choice = readChoice();
    switch (choice)
    {
    case 1:
    {
      string name;
      int score;
      cout << "Enter student name: ";
      cin >> name;
      cout << "Enter student score: ";
      cin >> score;
      university.addStudent(name, score);
    }
    case 2:
    {
      university.displayStudents();
    }
    case 3:
    {
      university.displayBestStudents();
    }
    case 4:
    {
      string name;
      cout << "Enter student name to remove: ";
      cin >> name;
      university.removeStudent(name);
    }
    case 0:
    {
      cout << "Invalid choice. Please try again." << endl;
    }
    }
  } while (choice != 0);
  return 0;
}