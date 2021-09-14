#include <karel.h>
#define nSPEED 100
#define qSPEED 0

void turnRight();
void turn180();
void turnNorth();//	пн ^
void turnSouth();// пд v
void turnEast(); // сх >
void turnWest(); // зх <

int backIsClear();

void TakeBeepers();
int takeBeeper();
int PutBeeper();

void goEnd();
int move();

void Trojuholniky();
int printSides(int a, int b, int c);

int main()
{
	turnOn("ps3.kw");
	setStepDelay(nSPEED);
	Trojuholniky();
	turnOff();
	return 0;
}

void Trojuholniky()
{
	int p = 0;
	int a, b, c;
	while (beepersPresent())
	{
		pickBeeper();
		p++;
	}
	for (int i = 0; i < p; i++)
	{
		putBeeper();
	}
	turnSouth();
	move();
	turnLeft();//>
	a = 3; b = 4; c = 5;
	for (a = 3; a + b + c < p; a++)
	{
		for (b = 4; a + b + c < p; b++)
		{
			for (c = 5; a + b + c < p; c++)
			{
				if ((a*a + b * b) == (c*c))
				{
					if (!printSides(a, b, c))
					{
						return;
					}
				}
			}
			c = 5;
		}
		b = 4;
	}

}

int printSides(int a, int b, int c)
{
	if (a < b)
	{
		for (int i = 0; i < a; i++)
		{
			putBeeper();
		}
		move();
		for (int i = 0; i < b; i++)
		{
			putBeeper();
		}
		move();
		for (int i = 0; i < c; i++)
		{
			putBeeper();
		}
		if (rightIsClear())
		{
			turn180();
			goEnd();
			turnLeft();
			move();
			turnLeft();
			return 1;
		}
		else
		{
			turnLeft();
			goEnd();
			return 0;
		}
	}
	return 1;
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

int takeBeeper()
{
	if (beepersPresent())
	{
		pickBeeper();
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

void turnNorth()
{
	setStepDelay(qSPEED);
	while (!facingNorth())
	{
		turnLeft();
	}
	setStepDelay(nSPEED);
}

void turnSouth()
{
	setStepDelay(qSPEED);
	while (!facingSouth())
	{
		turnLeft();
	}
	setStepDelay(nSPEED);
}

void turnEast()
{
	setStepDelay(qSPEED);
	while (!facingEast())
	{
		turnLeft();
	}
	setStepDelay(nSPEED);
}

void turnWest()
{
	setStepDelay(qSPEED);
	while (!facingWest())
	{
		turnLeft();
	}
	setStepDelay(nSPEED);
}
