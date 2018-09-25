
// 哲学家就餐问题
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#define N 5
#define LEFT i
#define RIGHT (i + 1) % N
using namespace std;

class Semaphore
{
  private:
    sem_t sem;

  public:
    Semaphore(int value = 1)
    {
        sem_init(&sem, 0, value);
    }
    void P()
    {
        sem_wait(&sem);
    }
    void V()
    {
        sem_post(&sem);
    }
};
Semaphore mutex[N];
pthread_t thread[N];
int id[N];
int add = 0;
void *solve(void *param)
{
    int i = *((int *)param);
        while (true)
    {
               if (add >= 30)
        {
            cout << "noodles is over" << endl;
                      break;
                  
        }
               cout << "philo" << i << "  thinking" << endl;
               if (i % 2 == 0)
        {
                      mutex[LEFT].P();
                      mutex[RIGHT].P();
                      cout << "philo" << i << "  eatting" << endl;
                      add++;
                      cout << add << endl;
                      mutex[RIGHT].V();
                      mutex[LEFT].V();
                  
        }
        else
        {
                      mutex[RIGHT].P();
                      mutex[LEFT].P();
                      cout << "philo" << i << "  eatting" << endl;
                      add++;
                      cout << add << endl;
                      mutex[LEFT].V();
                      mutex[RIGHT].V();
                  
        }
               sleep(1);
           
    }
}
void thread_create()
{
       int tmp;
       for (int i = 0; i < N; i++)
    {
              tmp = pthread_create(&thread[i], NULL, solve, &id[i]);
              if (tmp != 0)
        {
                      cout << "thread" << i << "error" << endl;
               
        }
          
    }
}
void thread_wait()
{
        for (int i = 0; i < N; i++)
    {
               pthread_join(thread[i], NULL);
           
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
    }
    thread_create();
    thread_wait();
    return 0;
}
