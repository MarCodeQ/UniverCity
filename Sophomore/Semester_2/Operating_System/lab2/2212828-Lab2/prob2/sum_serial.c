#include <stdio.h>

int main()
{
  int sum = 0;
  printf("Enter a number: ");
  int n = scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    sum += i;
  }
  printf("sum_serial = %d\n", sum);
}