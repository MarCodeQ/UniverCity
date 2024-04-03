#include <iostream>
#include <string>
#include <cstdlib> // For random number generation
using namespace std;
class Student
{
protected:
  string name;
  int score;

public:
  Student(const string &name) : name(name), score(0) {}

  virtual void DoAssignment() = 0;
  virtual void TakeTest() = 0;
  virtual void TakeExam() = 0;

  void DisplayInfo()
  {
    cout << "Name: " << name << ", Score: " << score << endl;
  }
};

class UniStudent : public Student
{
private:
  static const int numSemesters = 8;
  static const int numCourses = 4;
  static const int numAssignments = 3;
  static const int numTests = 2;
  static const int numExams = 1;

public:
  UniStudent(const string &name) : Student(name) {}

  void DoAssignment() override
  {
    for (int semester = 1; semester <= numSemesters; ++semester)
    {
      for (int course = 1; course <= numCourses; ++course)
      {
        for (int assignment = 1; assignment <= numAssignments; ++assignment)
        {
          // Randomly assign a score between 0 and 100
          score += rand() % 101;
        }
      }
    }
  }

  void TakeTest() override
  {
    for (int semester = 1; semester <= numSemesters; ++semester)
    {
      for (int course = 1; course <= numCourses; ++course)
      {
        for (int test = 1; test <= numTests; ++test)
        {
          // Randomly assign a score between 0 and 100
          score += rand() % 101;
        }
      }
    }
  }

  void TakeExam() override
  {
    for (int semester = 1; semester <= numSemesters; ++semester)
    {
      for (int course = 1; course <= numCourses; ++course)
      {
        // Randomly assign a score between 0 and 100
        score += rand() % 101;
      }
    }
  }
};

class CollegeStudent : public Student
{
private:
  static const int numSemesters = 4;
  static const int numCourses = 3;
  static const int numAssignments = 1;
  static const int numTests = 1;
  static const int numExams = 1;

public:
  CollegeStudent(const string &name) : Student(name) {}

  void DoAssignment() override
  {
    for (int semester = 1; semester <= numSemesters; ++semester)
    {
      for (int course = 1; course <= numCourses; ++course)
      {
        // Randomly assign a score between 0 and 100
        score += rand() % 101;
      }
    }
  }

  void TakeTest() override
  {
    for (int semester = 1; semester <= numSemesters; ++semester)
    {
      for (int course = 1; course <= numCourses; ++course)
      {
        // Randomly assign a score between 0 and 100
        score += rand() % 101;
      }
    }
  }

  void TakeExam() override
  {
    for (int semester = 1; semester <= numSemesters; ++semester)
    {
      // Randomly assign a score between 0 and 100
      score += rand() % 101;
    }
  }
};

int main()
{
  const int numStudents = 5;
  Student *students[numStudents];

  students[0] = new UniStudent("John");
  students[1] = new CollegeStudent("Alice");
  students[2] = new UniStudent("Bob");
  students[3] = new CollegeStudent("Emily");
  students[4] = new UniStudent("David");

  for (int i = 0; i < numStudents; ++i)
  {
    students[i]->DoAssignment();
    students[i]->TakeTest();
    students[i]->TakeExam();
    students[i]->DisplayInfo();
  }

  for (int i = 0; i < numStudents; ++i)
  {
    delete students[i];
  }

  return 0;
}