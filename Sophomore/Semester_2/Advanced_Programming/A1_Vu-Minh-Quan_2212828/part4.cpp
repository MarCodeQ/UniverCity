#include <iostream>
using namespace std;
void task1()
{
  int scores[10];
  int sum = 0;

  // Input scores
  for (int i = 0; i < 10; i++)
  {
    cout << "Enter score for student " << i + 1 << ": ";
    cin >> scores[i];
    sum += scores[i];
  }

  // Calculate average
  double average = static_cast<double>(sum) / 10;

  // Display average
  cout << "Average score: " << average << endl;
  cout << "End of task 1\n\n";
}

void task2()
{
  int secretNumber = 15;
  int guess;

  do
  {
    cout << "Make a guess (between 0 and 20): ";
    cin >> guess;

    if (guess < secretNumber)
    {
      cout << "Too small! Try again." << endl;
    }
    else if (guess > secretNumber)
    {
      cout << "Too large! Try again." << endl;
    }
  } while (guess != secretNumber);

  cout << "Congratulations! You guessed the secret number." << endl;
  cout << "End of task 2\n\n";
}

int main()
{
  task1();
  task2();

  return 0;
}
