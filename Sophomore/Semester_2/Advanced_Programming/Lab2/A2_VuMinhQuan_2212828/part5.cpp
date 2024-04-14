#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

private:
  int semesters;
};

class University
{
public:
  University(const string &name) : name(name) {}

  void addUniStudent()
  {
    string name, dob, school, course;
    int semesters;
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

    uniStudents.push_back(UniStudent(name, dob, school, course, semesters));
  }

  void addCollegeStudent()
  {
    string name, dob, school, course;
    int semesters;

    cout << "Enter CollegeStudent Name: ";
    cin >> name;
    cout << "Enter CollegeStudent Date of Birth (YYYY-MM-DD): ";
    cin >> dob;
    cout << "Enter CollegeStudent School: ";
    cin >> school;
    cout << "Enter CollegeStudent Course: ";
    cin >> course;
    cout << "Enter CollegeStudent Semesters: ";
    cin >> semesters;

    collegeStudents.push_back(CollegeStudent(name, dob, school, course, semesters));
  }

  void displayAllStudents() const
  {
    cout << "University Name: " << name << endl;
    cout << "University Students:\n";
    for (const auto &student : uniStudents)
    {
      student.displayDetails();
    }
    cout << "\nCollege Students:\n";
    for (const auto &student : collegeStudents)
    {
      student.displayDetails();
    }
  }

private:
  string name;
  vector<UniStudent> uniStudents;
  vector<CollegeStudent> collegeStudents;
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
  University university("My University");
  int choice = 0;

  do
  {
    choice = readChoice();

    switch (choice)
    {
    case 1:
      university.addUniStudent();
      break;
    case 2:
      university.addCollegeStudent();
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
