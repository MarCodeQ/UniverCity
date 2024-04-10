#include <stdio.h>
#include <pthread.h>
#define MAX_COUNT 10000
int count;
void *f_count(void *sid)
{
  int i;
  for (i = 0; i < MAX_COUNT; i++)
  {
    count = count + 1;
  }
  printf(" Thread %s : holding %d \n", (char *)sid, count);
  getc(stdin);
}
int main(int argc, char *argv[])
{
  printf(" Helloworld \n");
  pthread_t thread1, thread2;
  count = 0;
  /* Create i n d e p e n d e n t t h r e a d s each o f which w i l l e x e c u t e f u n c t i o n */
  pthread_create(&thread1, NULL, &f_count, "1");
  pthread_create(&thread2, NULL, &f_count, "2");
  // Wait f o r t h r e a d t h 1 f i n i s h
  pthread_join(thread1, NULL);
  // Wait f o r t h r e a d t h 1 f i n i s h
  pthread_join(thread2, NULL);
  getc(stdin);
  return 0;
}
