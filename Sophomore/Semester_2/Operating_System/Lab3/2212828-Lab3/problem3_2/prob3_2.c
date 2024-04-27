#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define BUF_SIZE 2
#define THREADS 1          // 1 producer and 1 consumer
#define LOOPS 3 * BUF_SIZE // variable
sem_t empty, full;
// Initiate shared buffer
int buffer[BUF_SIZE];
int fill = 0;
int use = 0;

void put(int value); // put data into buffer
int get();           // get data from buffer

void *producer(void *arg)
{
  int i;
  int tid = *((int *)arg);
  for (i = 0; i < LOOPS; i++)
  {
    sem_wait(&empty);
    put(i); // line P2
    printf("Producer %d put data %d\n", tid, i);
    sem_post(&full);
    sleep(1);
  }
  pthread_exit(NULL);
}

void *consumer(void *arg)
{
  int i, tmp = 0;
  int tid = *((int *)arg);
  while (1)
  {
    sem_wait(&full);
    tmp = get(); // line C2
    if (tmp == -1)
    {
      sem_post(&full); // Release the semaphore before exiting
      break;
    }
    printf("Consumer %d get data %d\n", tid, tmp);
    sleep(1);
    sem_post(&empty);
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
  int i, j;
  int tid[THREADS];
  pthread_t producers[THREADS];
  pthread_t consumers[THREADS];

  sem_init(&empty, 0, BUF_SIZE);
  sem_init(&full, 0, 0);

  for (i = 0; i < THREADS; i++)
  {
    tid[i] = i;
    // Create producer thread
    pthread_create(&producers[i], NULL, producer, (void *)&tid[i]);

    // Create consumer thread
    pthread_create(&consumers[i], NULL, consumer, (void *)&tid[i]);
  }

  for (i = 0; i < THREADS; i++)
  {
    pthread_join(producers[i], NULL);
    pthread_join(consumers[i], NULL);
  }

  sem_destroy(&empty);
  sem_destroy(&full);

  return 0;
}

void put(int value)
{
  buffer[fill] = value;         // line f1
  fill = (fill + 1) % BUF_SIZE; // line f2
}

int get()
{
  int tmp = buffer[use];      // line g1
  buffer[use] = -1;           // clean the item
  use = (use + 1) % BUF_SIZE; // line g2
  if (tmp == LOOPS - 1)
    return -1; // Indicate end of data for consumer
  return tmp;
}
