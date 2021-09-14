#include <karel.h>
#define nSPEED 200
#define qSPEED 0

void turnRight();
void Triedenie();
void StartPosition();
int moveBeepers();
void turn180();
int backIsClear();
void TakeBeepers();
int PutBeeper();
void goEnd();
int move();

int main()
{
	turnOn("task_2.kw");
	setStepDelay(nSPEED);
	Triedenie();
	turnOff();
	return 0;
}

void Triedenie()
{
	StartPosition();//> v dole
	while (frontIsClear())
	{
		if (!moveBeepers())
		{
			break;
		}
	}
	StartPosition();
	goEnd();
}

int moveBeepers()
{
	if (!backIsClear() && (facingEast() || facingWest()))
	{
		while (frontIsClear())
		{
			TakeBeepers();
			movek();
		}
		TakeBeepers();

		if (noBeepersInBag())
		{
			return 0;
		}
		else //BeepersInBag()
		{
			if (facingEast())//>
			{
				goEnd();//>>>
				turn180();//<
				while (frontIsClear() && PutBeeper())
				{
					movek();//<<<
				}
				goEnd();//<<<
				turnRight();//^
				if (move())
				{
					turnRight();//>
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if (facingWest())//<
			{
				turn180();//>
				goEnd();//>>>
				turn180();//<
				while (frontIsClear() && PutBeeper())
				{
					movek();//<<<
				}
				goEnd();//<<<
				turnRight();//^
				if (move())
				{
					turnRight();//>
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 0;
}

void StartPosition()
{
	while (!facingSouth())
	{
		turnLeft();
	}
	goEnd();//v
	turnRight();//<
	goEnd();
	turn180();//>
}

void turnRight()
{
	setStepDelay(qSPEED);
	turnLeft();
	turnLeft();
	setStepDelay(nSPEED);
	turnLeft();
}

int move()
{
	if (frontIsClear())
	{
		movek();
		return 1;
	}
	return 0;
}

void TakeBeepers()
{
	while (beepersPresent())
	{
		pickBeeper();
	}
}

void goEnd()
{
	while (frontIsClear())
	{
		movek();
	}
}

int PutBeeper()
{
	if (beepersInBag())
	{
		putBeeper();
		return 1;
	}
	return 0;
}

int backIsClear()
{
	setStepDelay(qSPEED);
	turn180();
	if (frontIsClear())
	{
		turn180();
		setStepDelay(nSPEED);
		return 1;
	}
	turn180();
	setStepDelay(nSPEED);
	return 0;
}

void turn180()
{
	setStepDelay(qSPEED);
	turnLeft();
	setStepDelay(nSPEED);
	turnLeft();
}