#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	queue *q = queueInit();
	printf("Initialization.\n");
	printf("is Empty: %d\n", isEmpty(q));
	enqueue(q, "abc");
	printf("enqueued abc\n");
	printf("is Empty: %d\n", isEmpty(q));
	printf("peek : %s\n", peek(q));
	enqueue(q, "efg");
	printf("enqueued efg\n");
	printf("is Empty: %d\n", isEmpty(q));
	printf("peek : %s\n", peek(q));
	dequeue(q);
	printf("dequeue.\n");
	printf("is Empty: %d\n", isEmpty(q));
	printf("peek : %s\n", peek(q));
	dequeue(q);
	printf("dequeue.\n");
	printf("is Empty: %d\n", isEmpty(q));
	printf("peek : %s\n", peek(q));
	return (0);
}



// Function used for the test
// Don't go further :)

