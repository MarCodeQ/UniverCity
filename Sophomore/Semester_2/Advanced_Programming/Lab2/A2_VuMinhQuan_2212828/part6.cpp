#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Student
{
public:
  Student(const string &name, const string &dob, const string &school, const string &course)
      : name(name), dob(dob), school(school), course(course) {}

  virtual ~Student() {}

  virtual void displayDetails() const
  {
    cout << "Name: " << name << ", Date of Birth: " << dob
         << ", School: " << school << ", Course: " << course;
  }

  virtual void DoAssignment() = 0;
  virtual void TakeTest() = 0;
  virtual void TakeExam() = 0;

protected:
  string name;
  string dob;
  string school;
  string course;
};

class UniStudent : public Student
{
public:
  UniStudent(const string &name, const string &dob, const string &school, const string &course, int semesters)
      : Student(name, dob, school, course), semesters(semesters) {}

  void displayDetails() const override
  {
    Student::displayDetails();
    cout << ", Semesters: " << semesters << endl;
  }

  void DoAssignment() override
  {
    // Simulate assigning scores for assignments
    for (int i = 1; i <= semesters * 4; ++i)
    {
      cout << "Assignment " << i << " Score: " << rand() % 100 + 1 << endl;
    }
  }

  void TakeTest() override
  {
    // Simulate taking tests
    for (int i = 1; i <= semesters * 4; ++i)
    {
      cout << "Test " << i << " Score: " << rand() % 100 + 1 << endl;
    }
  }

  void TakeExam() override
  {
    // Simulate taking exams
    for (int i = 1; i <= semesters; ++i)
    {
      cout << "Exam Semester " << i << " Score: " << rand() % 100 + 1 << endl;
    }
  }

private:
  int semesters;
};

class CollegeStudent : public Student
{
public:
  CollegeStudent(const string &name, const string &dob, const string &school, const string &course, int semesters)
      : Student(name, dob, school, course), semesters(semesters) {}

  void displayDetails() const override
  {
    Student::displayDetails();
    cout << ", Semesters: " << semesters << endl;
  }

  void DoAssignment() override
  {
    // Simulate assigning scores for assignments
    for (int i = 1; i <= semesters * 3; ++i)
    {
      cout << "Assignment " << i << " Score: " << rand() % 100 + 1 << endl;
    }
  }

  void TakeTest() override
  {
    // Simulate taking tests
    for (int i = 1; i <= semesters * 3; ++i)
    {
      cout << "Test " << i << " Score: " << rand() % 100 + 1 << endl;
    }
  }

  void TakeExam() override
  {
    // Simulate taking exams
    for (int i = 1; i <= semesters; ++i)
    {
      cout << "Exam Semester " << i << " Score: " << rand() % 100 + 1 << endl;
    }
  }

private:
  int semesters;
};

class University
{
public:
  University(const string &name) : name(name) {}

  void addUniStudent(const string &name, const string &dob, const string &school, const string &course, int semesters)
  {
    uniStudents.push_back(new UniStudent(name, dob, school, course, semesters));
  }

  void addCollegeStudent(const string &name, const string &dob, const string &school, const string &course, int semesters)
  {
    collegeStudents.push_back(new CollegeStudent(name, dob, school, course, semesters));
  }

  void displayAllStudents() const
  {
    cout << "University Name: " << name << endl;
    cout << "University Students:\n";
    for (const auto &student : uniStudents)
    {
      student->displayDetails();
      student->DoAssignment();
      student->TakeTest();
      student->TakeExam();
      cout << endl;
    }
    cout << "\nCollege Students:\n";
    for (const auto &student : collegeStudents)
    {
      student->displayDetails();
      student->DoAssignment();
      student->TakeTest();
      student->TakeExam();
      cout << endl;
    }
  }

  ~University()
  {
    for (auto student : uniStudents)
    {
      delete student;
    }
    for (auto student : collegeStudents)
    {
      delete student;
    }
  }

private:
  string name;
  vector<Student *> uniStudents;
  vector<Student *> collegeStudents;
};

int readChoice()
{
  int choice;
  cout << "\nStudent Management System\n";
  cout << "1. Add UniStudent\n";
  cout << "2. Add CollegeStudent\n";
  cout << "3. Display Students\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main()
{
  srand(time(nullptr));

  University university("My University");
  int choice = 0;
  string name, dob, school;
  int course, semesters;
  do
  {
    choice = readChoice();
    switch (choice)
    {
    case 1:
      cout << "Enter UniStudent Name: ";
      cin >> name;
      cout << "Enter UniStudent Date of Birth (YYYY-MM-DD): ";
      cin >> dob;
      cout << "Enter UniStudent School: ";
      cin >> school;
      cout << "Enter UniStudent Course: ";
      cin >> course;
      cout << "Enter UniStudent Semesters: ";
      cin >> semesters;
      university.addUniStudent(name, dob, school, course, semesters);
      break;
    case 2:
      cout << "Enter CollegeStudentName : ";
      cin >> name;
      cout << "Enter CollegeStudent Date of Birth (YYYY-MM-DD): ";
      cin >> dob;
      cout << "Enter CollegeStudent School: ";
      cin >> school;
      cout << "Enter CollegeStudent Course: ";
      cin >> course;
      cout << "Enter CollegeStudent Semesters: ";
      cin >> semesters;
      university.addCollegeStudent(name, dob, school, course, semesters);
      break;
    case 3:
      university.displayAllStudents();
      break;
    case 0:
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  return 0;
}
