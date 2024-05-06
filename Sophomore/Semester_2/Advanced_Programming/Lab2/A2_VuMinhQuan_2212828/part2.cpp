#include <iostream>

using namespace std;
void storeStudent(string *student, int index, const string &name, float *scorelist, const float &score)
{
  student[index] = name;
  scorelist[index] = score;
}
int readChoice()
{
  int choice;
  cout << "Enter 0 to quit" << endl;
  cout << "Enter 1 to add a student" << endl;
  cout << "Enter 2 to display all students" << endl;
  cout << "Enter 3 to find student has highest score" << endl;
  cin >> choice;
  return choice;
}

int main()
{
  string studentlist[100];
  string *student = studentlist;
  float scorelist[100];
  float *score = scorelist;
  int last = 0;
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
      cout << "Enter the name of the student to add: ";
      cin >> student[last];
      cout << "Enter the score of the student: ";
      cin >> score[last];
      storeStudent(student, last, student[last], score, score[last]);
      last++;
      break;
    }
    case 2:
    {
      cout << "These students are in the system: " << endl;
      for (int i = 0; i < last; ++i)
      {
        cout << "Student: " << student[i] << " with a score of: " << score[i] << endl;
      }
      cout << "\n\n";
      break;
    }
    case 3:
    {
      cout << "These students with the highest score is " << endl;
      float max = 0;
      for (int i = 0; i < last; ++i)
      {
        if (score[i] > max)
        {
          max = score[i];
        }
      }
      for (int i = 0; i < last; ++i)
      {
        if (score[i] == max)
        {
          cout << "Student: " << student[i] << " with a score of: " << score[i] << endl;
        }
      }
      cout << "\n\n";
      break;
    }
    default:
      cout << "Invalid choice. Try again" << endl;
      break;
    }
  } while (choice != 0);
  return 0;
}