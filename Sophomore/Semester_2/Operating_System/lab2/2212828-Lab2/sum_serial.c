#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long int calcu(long long int n)
{
  long long int sum = 0;
  for (long long int i = 1; i <= n; i++)
  {
    sum += i;
  }
  return sum;
}
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("ERROR: inputs mustbe ./sum_serial n\n");
    return 1;
  }
  long long int n = atoll(argv[1]);
  clock_t start = clock();
  long long int sum = calcu(n);
  clock_t end = clock();
  double time = (double)(end - start) / CLOCKS_PER_SEC;
  printf("sum_serial = %lld, Runtime = %f\n", sum, time);
}