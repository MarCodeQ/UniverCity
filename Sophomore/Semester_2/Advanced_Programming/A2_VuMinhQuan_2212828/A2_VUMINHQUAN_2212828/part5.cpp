#include <iostream>
#include <string>
using namespace std;
class Student
{
protected:
  string name;
  string schoolName;
  string courseName;

public:
  Student(const string &name, const string &schoolName, const string &courseName)
      : name(name), schoolName(schoolName), courseName(courseName) {}

  virtual void displayInfo()
  {
    cout << "Name: " << name << endl;
    cout << "School Name: " << schoolName << endl;
    cout << "Course Name: " << courseName << endl;
  }
};

class UniStudent : public Student
{
private:
  int semesters;

public:
  UniStudent(const string &name, const string &schoolName, const string &courseName, int semesters)
      : Student(name, schoolName, courseName), semesters(semesters) {}

  void displayInfo() override
  {
    Student::displayInfo();
    cout << "Semesters: " << semesters << endl;
  }
};

class CollegeStudent : public Student
{
private:
  int semesters;

public:
  CollegeStudent(const string &name, const string &schoolName, const string &courseName, int semesters)
      : Student(name, schoolName, courseName), semesters(semesters) {}

  void displayInfo() override
  {
    Student::displayInfo();
    cout << "Semesters: " << semesters << endl;
  }
};

int main()
{
  Student *student1 = new UniStudent("John Doe", "University of XYZ", "Computer Science", 8);
  Student *student2 = new CollegeStudent("Jane Smith", "ABC College", "Business Administration", 4);

  student1->displayInfo();
  cout << endl;
  student2->displayInfo();

  delete student1;
  delete student2;

  return 0;
}