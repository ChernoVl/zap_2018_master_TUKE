#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define EPS 0.0001

int workCash();
int chekValues(float);
void surrender(float);

int main(void)
{
	if (workCash())
	{
		return 1;
	}
	return 0;
}

int workCash()
{
	float bill;
	printf("Enter value of your bill: ");
	scanf("%f", &bill);
	if (!(bill > 0 && bill < 10000))
	{
		printf("Wrong input!\n");
		return 1;
	}
	float a;
	char c;
	float sum = 0;
	printf("Insert money for payment: ");
	do
	{
		scanf("%f%c", &a, &c);
		if (chekValues(a))
		{
			sum += a;
		}
		else
		{
			if (floorf(a) * 100 != rintf(a * 100))
			{
				printf("%.2f is invalid!\n", a);
			}
			else
			{
				printf("%.f is invalid!\n", a);
			}
			return 1;
		}
	} while (a != 0 && c != '\n');
	if (sum < 0 || sum > 10000)
	{
		printf("Wrong input!\n");
		return 1;
	}
	printf("You have inserted: %0.2f\n", sum);
	if (rintf(bill * 100) < rintf(sum * 100))
	{
		printf("To return: %.2f\n", sum - bill);
		printf("Collect your payback:");
		surrender(rintf(sum * 100) - rintf(bill * 100));
		printf("\n");
	}
	else if (rintf(bill * 100) > rintf(sum * 100))
	{
		printf("Not enough money!\n");
	}
	else
	{
		printf("To return: 0\n");
	}
	return 0;
}

int chekValues(float x)
{
	if (x == 100 || x == 50 || x == 20 || x == 10 || x == 5 || x == 2 || x == 1 || x == 0.5 || 
		(x > 0.2 - EPS && x < 0.2 + EPS)   || (x > 0.1 - EPS && x < 0.1 + EPS)   || (x > 0.05 - EPS && x < 0.05 + EPS) || 
		(x > 0.02 - EPS && x < 0.02 + EPS) || (x > 0.01 - EPS && x < 0.01 + EPS) || x==0)
	{
		return 1;
	}
	return 0;
}

void surrender(float x)
{
	//x /= 100;
	while ((x - 100 * 100) >= 0)
	{
		printf(" 100");
		x -= 100 * 100;
	} 
	while (x - 50 * 100 >= 0)
	{
		printf(" 50");
		x -= 50 * 100;
	}
	while (x - 20 * 100 >= 0)
	{
		printf(" 20");
		x -= 20 * 100;
	}
	while (x - 10 * 100 >= 0)
	{
		printf(" 10");
		x -= 10 * 100;
	}
	while (x - 5 * 100 >= 0)
	{
		printf(" 5");
		x -= 5 * 100;
	}
	while (x - 2 * 100 >= 0)
	{
		printf(" 2");
		x -= 2 * 100;
	}
	while (x - 1 * 100 >= 0)
	{
		printf(" 1");
		x -= 1 * 100;
	}
	while (x - 0.5 * 100 >= 0)
	{
		printf(" 0.50");
		x -= 0.5 * 100;
	}
	while (x - 0.2 * 100 >= 0)
	{
		printf(" 0.20");
		x -= 0.2 * 100;
	}
	while (x - 0.1 * 100 >= 0)
	{
		printf(" 0.10");
		x -= 0.1 * 100;
	}
	while (x - 0.05 * 100 >= 0)
	{
		printf(" 0.05");
		x -= 0.05 * 100;
	}
	while (x - 0.02 * 100 >= 0)
	{
		printf(" 0.02");
		x -= 0.02 * 100;
	}
	while (x - 0.01 * 100 >= 0)
	{
		printf(" 0.01");
		x -= 0.01 * 100;
	}
}