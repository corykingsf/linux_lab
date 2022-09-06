#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int ticketAmout = 2;  // 票的数量: 全局变量

void* ticketAgent(void* arg){

    int t = ticketAmout;

    if (t > 0){
        printf("One ticket sold\n");
        t--;
    }else{
        printf("Ticket sold out\n");
    }

    ticketAmout = t;

    pthread_exit(0);
}

int main(int argc, char const* agrv[]){

    pthread_t ticketAgent_tid[2];

    for(int i = 0; i < 2; i++){
        pthread_create(ticketAgent_tid+i, NULL, ticketAgent, NULL);
    }

    for (int i = 0; i < 2; i++){
        pthread_join(ticketAgent_tid[i], NULL);
    }

    sleep(1);
    printf("The left ticket is %d\n", ticketAmout);

    return 0;
}
