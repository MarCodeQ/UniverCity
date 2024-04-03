#include <iostream>
using namespace std;

void sumTripple(float a, float b, float c)
{
  cout << "Sum: " << a + b + c << endl;
}
void mulTripple(float a, float b, float c)
{
  cout << "Multiplication: " << a * b * c << endl;
}
void aveTripple(float a, float b, float c)
{
  cout << "Average: " << (a + b + c) / 3 << endl;
}
void task1()
{
  float a, b, c;
  cin >> a;
  while (a != -1)
  {
    cin >> b;
    while (b != -1)
    {
      cin >> c;
      while (c != -1)
      {
        sumTripple(a, b, c);
        mulTripple(a, b, c);
        aveTripple(a, b, c);
        cin >> c;
      }
      break;
      cin >> b;
    }
    break;
    cin >> a;
  }
  cout << "End of task 1\n\n";
  return;
}

void task2()
{
  int choice;
  while (true)
  {
    cout << "Choose a shape to calculate its area:\n";
    cout << "1. Square\n";
    cout << "2. Rectangle\n";
    cout << "3. Circle\n";
    cout << "4. Triangle\n";
    cout << "-1. Exit\n";
    cin >> choice;

    if (choice == -1)
    {
      break;
    }

    switch (choice)
    {
    case 1:
    {
      float side;
      cout << "Enter the side length of the square: ";
      cin >> side;
      float area = calculateSquareArea(side);
      cout << "Area of the square: " << area << endl;
      break;
    }
    case 2:
    {
      float length, width;
      cout << "Enter the length and width of the rectangle: ";
      cin >> length >> width;
      float area = calculateRectangleArea(length, width);
      cout << "Area of the rectangle: " << area << endl;
      break;
    }
    case 3:
    {
      float radius;
      cout << "Enter the radius of the circle: ";
      cin >> radius;
      float area = calculateCircleArea(radius);
      cout << "Area of the circle: " << area << endl;
      break;
    }
    case 4:
    {
      float base, height;
      cout << "Enter the base and height of the triangle: ";
      cin >> base >> height;
      float area = calculateTriangleArea(base, height);
      cout << "Area of the triangle: " << area << endl;
      break;
    }
    default:
      cout << "Invalid choice. Please try again.\n";
      break;
    }
  }
}

float calculateSquareArea(float side)
{
  return side * side;
}

float calculateRectangleArea(float length, float width)
{
  return length * width;
}

float calculateCircleArea(float radius)
{
  return 3.14159 * radius * radius;
}

float calculateTriangleArea(float base, float height)
{
  return 0.5 * base * height;
}

int main()
{
  task1();
  task2();
  return 0;
}