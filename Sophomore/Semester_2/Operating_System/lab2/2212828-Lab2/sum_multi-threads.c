#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
typedef struct
{
  long long int start;
  long long int end;
  long long int sum;
} Threadform;

void *calcu(void *arg)
{
  Threadform *args = (Threadform *)arg;
  args->sum = 0;
  for (long long int i = args->start; i <= args->end; i++)
  {
    args->sum += i;
  }
  return NULL;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("ERROR: input mustbe ./sum_multi-thread threads n\n");
    return 1;
  }
  long long int n = atoll(argv[2]);
  int numThreads = atoi(argv[1]);
  clock_t start = clock();
  pthread_t threads[numThreads];
  Threadform threadform[numThreads];
  long long int eachThreadCal = n / numThreads;
  for (int i = 0; i < numThreads; i++)
  {
    threadform[i].start = i * eachThreadCal + 1;
    threadform[i].end = (i == numThreads - 1) ? n : (i + 1) * eachThreadCal;
    pthread_create(&threads[i], NULL, calcu, (void *)&threadform[i]);
  }
  long long int sum = 0;
  for (int i = 0; i < numThreads; i++)
  {
    pthread_join(threads[i], NULL);
    sum += threadform[i].sum;
  }
  clock_t end = clock();
  double time = (double)(end - start) / CLOCKS_PER_SEC;
  printf("sum_multi-threads = %lld, Runtime = %f\n", sum, time);
}