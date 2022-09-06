#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg){ // 线程函数
	sleep(3);
	printf("In New Thread\n");
}

int main(){

	pthread_t tid; // Thread id

	// 线程创建函数
	/** 参数列表:
	* 1.Thread id address
	* 2.Thread attribute address
	* 3.Thread function address
	* 4.Thread parameters address
	*/
	pthread_create(&tid, NULL, threadFunc, NULL);

	// 等待指定的线程结束
	 pthread_join(tid, NULL);

	printf("In Main Thread\n");

	return 0;
}
