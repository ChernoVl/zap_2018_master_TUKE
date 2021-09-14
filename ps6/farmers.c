#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int farmers,//1 - кількість фермерів
		animals,//3 - количество животных на каждой из ферм
		k_ekolog_approach;//4 - коэффициент экологического подхода фермера
	double area;//2 - розмір ферми в кв метрах
	double animal_occupies;
	double grand = 0;
	char c;
	scanf("%d%c", &farmers, &c);
	if (farmers >= 0 && farmers <= 20)
	{
		do
		{
			scanf("%lf%d%d%c", &area, &animals, &k_ekolog_approach, &c);
			if (area >= 0 && area <= 10000 &&
				animals >= 0 && animals <= 10000 &&
				k_ekolog_approach >= 0 && k_ekolog_approach <= 10000)
			{
				animal_occupies = roundl((double)area / (double)animals * 100) / 100;
				grand += animal_occupies * (double)k_ekolog_approach *(double)animals;;
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
	printf("Total donation: %.2f\n", grand);
	return 0;
}