#include <bits/stdc++.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;

typedef struct thread_data {
   int result;

} thread_data;

struct marks{
    int number1;
    int number2;
} m;

void * multOfNumbers(void *arg)
{
    thread_data *tdata=(thread_data *)arg;
    int mul{0};
    mul = m.number1 * m.number2;

    tdata->result=mul;
    pthread_exit(NULL);
}

int32_t main() {
    pthread_t thread1, thread2;
    thread_data tdata;
    cout << "Enter the first number = ";
    cin >> m.number1;
    cout << "Enter the second number = ";
    cin >> m.number2;

    pthread_create(&thread1, NULL, multOfNumbers, (void *)&tdata);
    sleep(1);

    cout << "The multiplication of given numbers is = " << tdata.result << endl;

    return 0;
}
