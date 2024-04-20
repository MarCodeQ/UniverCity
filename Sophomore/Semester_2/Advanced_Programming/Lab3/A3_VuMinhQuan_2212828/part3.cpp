#include <iostream>
#include <vector>
#include <memory>
using namespace std;
struct Student
{
  string name;
  float score;

  Student(const string &n, float s) : name(n), score(s) {}

  void display() const
  {
    cout << "Student: " << name << " with a score of: " << score << endl;
  }
};

void storeStudent(vector<shared_ptr<Student>> &students, const string &name, float score)
{
  students.push_back(make_shared<Student>(name, score));
}

int readChoice()
{
  int choice;
  cout << "\nStudent Management System\n";
  cout << "0. Exit\n";
  cout << "1. Add Student\n";
  cout << "2. Display Students\n";
  cout << "3. Display best students\n";
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main()
{
  vector<shared_ptr<Student>> students;
  int choice = 0;

  do
  {
    choice = readChoice();

    switch (choice)
    {
    case 0:
      cout << "Exiting..." << endl;
      break;
    case 1:
    {
      string name;
      float score;
      cout << "Enter the name of the student to add: ";
      cin >> name;
      cout << "Enter the score of the student: ";
      cin >> score;
      storeStudent(students, name, score);
      break;
    }
    case 2:
    {
      cout << "These students are in the system:" << endl;
      for (const auto &student : students)
      {
        student->display();
      }
      cout << "\n\n";
      break;
    }
    case 3:
    {
      cout << "The student with the highest score is:" << endl;
      if (!students.empty())
      {
        float maxScore = students.front()->score;
        for (const auto &student : students)
        {
          if (student->score > maxScore)
          {
            maxScore = student->score;
          }
        }
        for (const auto &student : students)
        {
          if (student->score == maxScore)
          {
            student->display();
          }
        }
      }
      else
      {
        cout << "No students in the system." << endl;
      }
      cout << "\n\n";
      break;
    }
    default:
      cout << "Invalid choice. Try again." << endl;
      break;
    }
  } while (choice != 0);

  return 0;
}
