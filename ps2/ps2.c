#include <karel.h>
#define nSPEED 100
#define qSPEED 0

void turnRight();
void turn180();
void turnNorth();//	�� ^
void turnSouth();// �� v
void turnEast(); // �� >
void turnWest(); // �� <

void StartPosition();
int backIsClear();
int nRnBS();

void TakeBeepers();
int takeBeeper();
int PutBeeper();

void goEnd();
int move();

void GreatView();
int around1Beep();// 1 - ���� ������� ������� ���� 1 ����, ������ 0 
int seek2Beep();


int main()
{
	turnOn("ps2.kw");
	setStepDelay(nSPEED);
	GreatView();
	turnOff();
	return 0;
}

void GreatView()
{
	StartPosition();
	while (!around1Beep());
	if (!beepersPresent())
	{
		while (move())
		{
			if (beepersPresent())
			{
				break;
			}
		}
	}
	if (!beepersPresent())
	{
		turnLeft();
		while (move())
		{
			if (beepersPresent())
			{
				break;
			}
		}
	}
	if (!beepersPresent())
	{
		turnLeft();
		while (move())
		{
			if (beepersPresent())
			{
				break;
			}
		}
	}
	if (!beepersPresent())
	{
		turnLeft();
		while (move())
		{
			if (beepersPresent())
			{
				break;
			}
		}
	}
	if (beepersPresent())
	{
		turnLeft();
		movek();
		turn180();
	}
}

int around1Beep()
{
	//������ ������� �� ������ �����
	while (frontIsClear())
	{
		takeBeeper();
		movek();
	}
	takeBeeper();
	turnLeft();//>
	while (frontIsClear())
	{
		takeBeeper();
		movek();
	}
	takeBeeper();
	turnLeft();//^
	while (frontIsClear())
	{
		takeBeeper();
		movek();
	}
	takeBeeper();
	turnLeft();//<
	while (frontIsClear())
	{
		takeBeeper();
		movek();
	}
	takeBeeper();
	turnLeft();//v
	//��������� ��������� �������
	//setStepDelay(qSPEED);
	if (seek2Beep())
	{
		StartPosition();
		return 0;
	}
	else
	{
		//�� �������� ��, ���� ��� ����� ���� ����� �������� �������
		StartPosition();
		return 1;
	}
	return 0;
}

int seek2Beep()
{
	if (nRnBS()) // �������� �� ��������� ���������
	{
		do {
			while (move())
			{
				if (beepersPresent())
				{
					do {
						while (move())
						{
							if (beepersPresent())
							{
								return 1;
							}
						}
						turnLeft();
					} while (!nRnBS());
					return 0;
				}
			}
			turnLeft();
		} while (!nRnBS());
	}
	return 0;
}

void StartPosition()
{
	setStepDelay(qSPEED);
	turnWest();//<
	goEnd();
	turnRight();//^
	goEnd();
	turnRight();//>	
	while (frontIsClear())
	{
		if (leftIsClear())
		{
			turnLeft();//^
			move();
			turnLeft();//<
			goEnd();
			turn180();//>
			break;
		}
		else
		{
			movek();
		}
	}
	if (!frontIsClear())
	{
		turn180();//<
		goEnd();
		turn180();//>
	}
	while (frontIsClear())
	{
		if (leftIsClear())
		{
			StartPosition();
			break;
		}
		else
		{
			movek();
		}
	}
	if (!frontIsClear())
	{
		turn180();//<
		goEnd();
		turnLeft();//v
	}
	setStepDelay(nSPEED);
}

int nRnBS()
{
	if (rightIsBlocked() && frontIsClear() && facingSouth() && leftIsClear() && !backIsClear())
	{
		return 1;
	}
	return 0;
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