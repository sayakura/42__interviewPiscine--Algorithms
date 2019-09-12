#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	//struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	struct s_tank *tank;

	tank = initTank();
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 90);
	tankPush(tank, 100);
	tankPush(tank, 100);

	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	return (0);
}



// Function used for the test
// Don't go further :)
