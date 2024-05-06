#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>

using namespace std;

class Student
{
public:
  Student(const string &name, const string &dob, const string &school, int course)
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
  int course;
};

class University
{
private:
  string name;
  vector<unique_ptr<Student>> students;
  static University *instance;

  University(const string &name) : name(name) {}

public:
  static University *getInstance(const string &name)
  {
    if (!instance)
    {
      instance = new University(name);
    }
    return instance;
  }

  void addStudent(unique_ptr<Student> student)
  {
    students.push_back(move(student));
  }

  void displayAllStudents() const
  {
    cout << "University Name: " << name << endl;
    cout << "Students:\n";
    for (const auto &student : students)
    {
      student->displayDetails();
      student->DoAssignment();
      student->TakeTest();
      student->TakeExam();
      cout << endl;
    }
  }

  static void destroyInstance()
  {
    if (instance)
    {
      delete instance;
      instance = nullptr;
    }
  }

  ~University()
  {
    students.clear();
  }
};

University *University::instance = nullptr;

class UniStudent : public Student
{
public:
  UniStudent(const string &name, const string &dob, const string &school, int course, int semesters)
      : Student(name, dob, school, course), semesters(semesters) {}

  void displayDetails() const override
  {
    Student::displayDetails();
    cout << ", Semesters: " << semesters << endl;
  }

  void DoAssignment() override
  {
    cout << "Filling UniStudent assignments with random scores:" << endl;
    for (int i = 1; i <= semesters * 4; ++i)
    {
      int score = rand() % 101;
      cout << "Assignment " << i << " Score: " << score << endl;
    }
  }

  void TakeTest() override
  {
    cout << "Filling UniStudent tests with random scores:" << endl;
    for (int i = 1; i <= semesters * 4; ++i)
    {
      int score = rand() % 101;
      cout << "Test " << i << " Score: " << score << endl;
    }
  }

  void TakeExam() override
  {
    cout << "Filling UniStudent exams with random scores:" << endl;
    for (int i = 1; i <= semesters * 4; ++i)
    {
      int score = rand() % 101;
      cout << "Exam Semester " << i << " Score: " << score << endl;
    }
  }

private:
  int semesters;
};

class CollegeStudent : public Student
{
public:
  CollegeStudent(const string &name, const string &dob, const string &school, int course, int semesters)
      : Student(name, dob, school, course), semesters(semesters) {}

  void displayDetails() const override
  {
    Student::displayDetails();
    cout << ", Semesters: " << semesters << endl;
  }

  void DoAssignment() override
  {
    cout << "Filling CollegeStudent assignments with random scores:" << endl;
    for (int i = 1; i <= semesters * 3; ++i)
    {
      int score = rand() % 101;
      cout << "Assignment " << i << " Score: " << score << endl;
    }
  }

  void TakeTest() override
  {
    cout << "Filling CollegeStudent tests with random scores:" << endl;
    for (int i = 1; i <= semesters * 3; ++i)
    {
      int score = rand() % 101;
      cout << "Test " << i << " Score: " << score << endl;
    }
  }

  void TakeExam() override
  {
    cout << "Filling CollegeStudent exams with random scores:" << endl;
    for (int i = 1; i <= semesters * 3; ++i)
    {
      int score = rand() % 101;
      cout << "Exam Semester " << i << " Score: " << score << endl;
    }
  }

private:
  int semesters;
};

int readChoice()
{
  int choice;
  cout << "\nStudent Management System\n";
  cout << "0. Exit\n";
  cout << "1. Add UniStudent\n";
  cout << "2. Add CollegeStudent\n";
  cout << "3. Display Students\n";
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main()
{
  srand(time(nullptr));

  unique_ptr<University> university(University::getInstance("My University"));
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
      if (course < 1 || course > 4)
      {
        cout << "Invalid course. Please enter a course between 1 and 4." << endl;
        break;
      }
      cout << "Enter UniStudent Semesters: ";
      cin >> semesters;
      if (semesters < 1 || semesters > 8)
      {
        cout << "Invalid semesters. Please enter a number between 1 and 8." << endl;
        break;
      }
      university->addStudent(make_unique<UniStudent>(name, dob, school, course, semesters));
      break;
    case 2:
      cout << "Enter CollegeStudent Name: ";
      cin >> name;
      cout << "Enter CollegeStudent Date of Birth (YYYY-MM-DD): ";
      cin >> dob;
      cout << "Enter CollegeStudent School: ";
      cin >> school;
      cout << "Enter CollegeStudent Course: ";
      cin >> course;
      if (course < 1 || course > 3)
      {
        cout << "Invalid course. Please enter a course between 1 and 3." << endl;
        break;
      }
      cout << "Enter CollegeStudent Semesters: ";
      cin >> semesters;
      if (semesters < 1 || semesters > 4)
      {
        cout << "Invalid semesters. Please enter a number between 1 and 4." << endl;
        break;
      }
      university->addStudent(make_unique<CollegeStudent>(name, dob, school, course, semesters));
      break;
    case 3:
      university->displayAllStudents();
      break;
    case 0:
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  University::destroyInstance();

  return 0;
}
