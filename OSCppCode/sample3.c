//sample3.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int global_var = 5;

int main(){
	static int static_var = 6;
	int local_var = 7;
	int*p = (int*)malloc(100);

	//Be careful： we must use %lx to show a 64bits address!!
	printf("the global_var address is %lx\n", &global_var);
	printf("the static_var address is %lx\n", &static_var);
	printf("the local_var address is %lx\n", &local_var);
	printf("the address which the p points to%lx\n", p);
	
	free(p);
	sleep(1000);//We need watch the process state, so let it sleep deeply.
	return 0;
}