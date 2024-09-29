#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(string str, int h, int t)
{
  char x = str[h];
  char y = str[t];
  if (str[h] == 32)
  {
    h++;
  }
  if (str[t] == 32)
  {
    t--;
  }
  if (h == t)
    return true;
  if (str[h] != str[t])
    return false;
  if (h < t + 1)
    return checkPalindrome(str, h + 1, t - 1);
  return true;
}
bool isPalindrome(string str)
{
  int n = str.length();
  if (n == 0)
    return true;
  return checkPalindrome(str, 0, n - 1);
}

int main()
{
  string str = "do geese see god";
  if (isPalindrome(str))
    cout << "Yes, it is a palindrome." << endl;
  else
    cout << "No, it is not a palindrome." << endl;
  return 0;
}