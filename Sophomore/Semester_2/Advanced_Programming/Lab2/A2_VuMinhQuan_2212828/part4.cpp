#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Student
{
public:
  Student(const std::string &name, int score) : name(name), score(score) {}
  ~Student() {}

  std::string getName() const { return name; }
  int getScore() const { return score; }

private:
  std::string name;
  int score;
};

class University
{
public:
  University(const std::string &name) : name(name) {}

  void addStudent(const std::string &name, int score)
  {
    students.push_back(Student(name, score));
  }

  void displayStudents() const
  {
    for (const auto &student : students)
    {
      std::cout << "Name: " << student.getName() << ", Score: " << student.getScore() << std::endl;
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
        std::cout << "Name: " << student.getName() << ", Score: " << student.getScore() << std::endl;
      }
    }
  }

  void removeStudent(const std::string &name)
  {
    students.erase(std::remove_if(students.begin(), students.end(),
                                  [&](const Student &student)
                                  { return student.getName() == name; }),
                   students.end());
  }

private:
  std::string name;
  std::vector<Student> students;
};

int main()
{
  University university("My University");

  int choice;
  while (true)
  {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Display Students" << std::endl;
    std::cout << "3. Display Best Students" << std::endl;
    std::cout << "4. Remove Student" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1)
    {
      std::string name;
      int score;
      std::cout << "Enter student name: ";
      std::cin >> name;
      std::cout << "Enter student score: ";
      std::cin >> score;
      university.addStudent(name, score);
    }
    else if (choice == 2)
    {
      university.displayStudents();
    }
    else if (choice == 3)
    {
      university.displayBestStudents();
    }
    else if (choice == 4)
    {
      std::string name;
      std::cout << "Enter student name to remove: ";
      std::cin >> name;
      university.removeStudent(name);
    }
    else if (choice == 5)
    {
      break;
    }
    else
    {
      std::cout << "Invalid choice. Please try again." << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}
