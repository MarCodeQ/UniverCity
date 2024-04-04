#include <iostream>
#include <string>

using namespace std;
const int MAX_STUDENTS = 100;
const int MATRIX_SIZE = 4;

void task1()
{
  string names[MAX_STUDENTS];
  int scores[MAX_STUDENTS];
  bool passed[MAX_STUDENTS];

  int numStudents = 0;
  cout << "Enter students' names and scores (0-100). Enter '-1' to stop.\n";

  while (numStudents < MAX_STUDENTS)
  {
    cout << "Enter student name: ";
    getline(cin, names[numStudents]);

    if (names[numStudents] == "-1")
    {
      break;
    }

    cout << "Enter student score: ";
    cin >> scores[numStudents];
    cin.ignore();

    passed[numStudents] = scores[numStudents] >= 50;

    numStudents++;
  }

  cout << "\nStudents' names, scores, and passed/failed status:\n";
  cout << "----------------------------------------------\n";
  cout << "Name\t\tScore\t\tStatus\n";
  cout << "----------------------------------------------\n";

  for (int i = 0; i < numStudents; i++)
  {
    cout << names[i] << "\t\t" << scores[i] << "\t\t" << (passed[i] ? "Passed" : "Failed") << "\n";
  }

  cout << "End of task 1\n\n";
}

void task2()
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];

  cout << "Enter elements of a 4x4 square matrix:\n";

  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      cout << "Enter element at position (" << i << ", " << j << "): ";
      cin >> matrix[i][j];
    }
  }

  cout << "\nMatrix:\n";
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      cout << matrix[i][j] << "\t";
    }
    cout << "\n";
  }

  int sum = 0;
  int rowSums[MATRIX_SIZE] = {0};
  int colSums[MATRIX_SIZE] = {0};
  int diagonalSum1 = 0;
  int diagonalSum2 = 0;

  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      sum += matrix[i][j];
      rowSums[i] += matrix[i][j];
      colSums[j] += matrix[i][j];

      if (i == j)
      {
        diagonalSum1 += matrix[i][j];
      }

      if (i + j == MATRIX_SIZE - 1)
      {
        diagonalSum2 += matrix[i][j];
      }
    }
  }

  cout << "\nSum of all elements in the matrix: " << sum << "\n";

  cout << "Sum of all elements in each row:\n";
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    cout << "Row " << i << ": " << rowSums[i] << "\n";
  }

  cout << "Sum of all elements in each column:\n";
  for (int j = 0; j < MATRIX_SIZE; j++)
  {
    cout << "Column " << j << ": " << colSums[j] << "\n";
  }

  cout << "Sum of all elements in the main diagonal: " << diagonalSum1 << "\n";
  cout << "Sum of all elements in the secondary diagonal: " << diagonalSum2 << "\n";

  cout << "End of task 2\n\n";
}

int main()
{
  task1();
  task2();

  return 0;
}
