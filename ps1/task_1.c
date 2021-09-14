#include <karel.h>
#define nSPEED 400
#define qSPEED 0

void jumpOver();
void turnRight();
void run();

int main()
{
	turnOn("task_1.kw");
	setStepDelay(nSPEED);
	run();
	turnOff();
	return 0;
}

void run()
{
	if(beepersInBag())
	{
		putBeeper();
		while(!facingEast())
		{
			turnLeft();
		}
		do{
			jumpOver();	
		}while(noBeepersPresent());
		pickBeeper();
		while(!facingWest())
		{
			turnLeft();
		}
		do{
			jumpOver();
		}while(noBeepersPresent());
		pickBeeper();
	}
}

void jumpOver()
{
	if(facingEast())
	{
		if(frontIsBlocked())
		{
			turnLeft();
			while(rightIsBlocked())
			{
				movek();
			}
			turnRight();
			movek();
			while(rightIsBlocked())
			{
				movek();
			}
			turnRight();
			while(frontIsClear())
			{
				movek();
			}
			turnLeft();
		}
		else
		{
			movek();
		}
	}
	else if(facingWest())
	{
		if(frontIsBlocked())
	        {
			turnRight();
		        while(leftIsBlocked())
		        {
				movek();
			}
			turnLeft();
			movek();
			while(leftIsBlocked())
			{
				movek();
			}
			turnLeft();
			while(frontIsClear())
			{
				movek();
			}
			turnRight();
		}
                else
		{
			movek();
		}
	}
}

void turnRight()
{
	setStepDelay(qSPEED);
	turnLeft();
	turnLeft();
	setStepDelay(nSPEED);
	turnLeft();
}