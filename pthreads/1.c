#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *myfunc (void *myvar);

int main(int *argc, char *argv[] ){

	pthread_t thread1, thread2;
	char *msg1 = "First theread";
	char *msg2 = "Secound theread";
	int ret1, ret2;

	ret1 = pthread_create(&thread1, NULL, myfunc, (void *) msg1);
	ret2 = pthread_create(&thread2, NULL, myfunc, (void *) msg2);
	
	printf("Main function after pthread_create\n");

	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("First theread ret1 = %d\n", ret1);
	printf("Second theread rest2 = %d\n", ret2);


return 0;
}

void *myfunc( void *myvar)
{
	char *msg;
	msg = (char *) myvar;

	int i;

	for(i = 0; i < 10; i++){
		printf("%s %d\n", msg, i);
		sleep(1);
	}
}	//return NULL;

/* Compliar

gcc nome_do_ficheiro.c -o saida -lpthread
./saida

*/