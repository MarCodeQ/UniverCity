#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
  Student(const string &name, int score) : name(name), score(score) {}
  ~Student() {}

  string getName() const
  {
    return name;
  }

  int getScore() const
  {
    return score;
  }

private:
  string name;
  int score;
};
void addStudent(Student **students, int &numStudents)
{
  string name;
  int score;
  cout << "Enter student name: ";
  cin >> name;
  cout << "Enter student score: ";
  cin >> score;

  Student *newStudent = new Student(name, score);

  Student **temp = new Student *[numStudents + 1];
  for (int i = 0; i < numStudents; i++)
  {
    temp[i] = students[i];
  }
  temp[numStudents] = newStudent;

  delete[] students;
  students = temp;

  numStudents++;

  cout << "Student added successfully!" << endl;
}

void displayStudents(const Student **students, int numStudents)
{
  cout << "List of students:" << endl;
  for (int i = 0; i < numStudents; i++)
  {
    cout << "Name: " << students[i]->getName() << ", Score: " << students[i]->getScore() << endl;
  }
}

void displayBestStudents(const Student **students, int numStudents)
{
  int maxScore = 0;

  for (int i = 0; i < numStudents; i++)
  {
    if (students[i]->getScore() > maxScore)
    {
      maxScore = students[i]->getScore();
    }
  }

  cout << "Best student(s):" << endl;
  for (int i = 0; i < numStudents; i++)
  {
    if (students[i]->getScore() == maxScore)
    {
      cout << "Name: " << students[i]->getName() << ", Score: " << students[i]->getScore() << endl;
    }
  }
}

void removeStudent(Student **students, int &numStudents, const string &name)
{
  int index = -1;

  for (int i = 0; i < numStudents; i++)
  {
    if (students[i]->getName() == name)
    {
      index = i;
      break;
    }
  }

  if (index != -1)
  {
    delete students[index];

    for (int i = index; i < numStudents - 1; i++)
    {
      students[i] = students[i + 1];
    }

    numStudents--;

    cout << "Student removed successfully!" << endl;
  }
  else
  {
    cout << "Student not found!" << endl;
  }
}

int main()
{
  Student **students = nullptr;
  int numStudents = 0;

  int choice;
  string name;

  while (true)
  {
    cout << "Menu:" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Display best student(s)" << endl;
    cout << "4. Remove a student" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      addStudent(students, numStudents);
      break;
    case 2:
      displayStudents(students, numStudents);
      break;
    case 3:
      displayBestStudents(students, numStudents);
      break;
    case 4:
      cout << "Enter student name to remove: ";
      cin >> name;
      removeStudent(students, numStudents, name);
      break;
    case 5:
      for (int i = 0; i < numStudents; i++)
      {
        delete students[i];
      }
      delete[] students;
      return 0;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }

    cout << endl;
  }
}