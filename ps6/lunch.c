#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double subsidies_for_students(double);
double subsidies_for_employees(double);

int main()
{
	char c;
	int people_lunch;
	int S_or_W;
	double price;
	double subsidy = 0, pay = 0;
	scanf("%d", &people_lunch);
	if (people_lunch >= 0 && people_lunch <= 20)
	{
		do
		{
			scanf("%d%lf%c", &S_or_W, &price, &c);
			if ((S_or_W == 1 || S_or_W == 2) && price > 0)
			{
				if (S_or_W == 1)
				{
					subsidy += subsidies_for_students(price);
					pay += price - roundl(subsidies_for_students(price) * 100) / 100;
				}
				else
				{
					subsidy += roundl(subsidies_for_employees(price) * 100) / 100;
					pay += price - roundl(subsidies_for_employees(price) * 100) / 100;
				}
			}
			else
			{
				printf("Wrong input!\n");
				return 1;
			}
		} while (c != '\n');
	}
	else
	{
		printf("Wrong input!\n");
		return 1;
	}
	printf("Total: %.2lf donated, %.2lf paid.\n", subsidy, pay);
	return 0;
}

double subsidies_for_students(double price)
{
	if (price >= 4)
	{
		return 2;
	}
	else if (price >= 2)
	{
		return 1;
	}
	else if (price >= 0)
	{
		return 0;
	}
	return -1;
}

double subsidies_for_employees(double price)
{
	if (price >= 1.80 && price < 3.60)
	{
		return price * 0.55 + 0.42;
	}
	else if (price >= 3.60 && price <= 5.40)
	{
		return 3.60 * 0.55 + 0.42;
	}
	else if (price > 5.40)
	{
		return subsidies_for_employees(price - 3.60) + (3.60 * 0.55 + 0.42);
	}
	return 0;
}