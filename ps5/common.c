#include <stdlib.h>
#include <stdio.h>

short int gcd(const short int a, const short int b)
{
	if ((a != 0 && a >= -1000 && a <= 1000) && (b != 0 && b >= -1000 && b <= 1000))
	{
		short int z;
		short int x, y;
		x = a; y = b;
		while (y)
		{
			z = y;
			y = (x % y);
			x = z;
		}
		return abs(x);
	}
	return -1;
}
int NSD(int a, int b)
{
	int z;
	while (b)
	{
		z = b;
		b = (a % b);
		a = z;
	}
	return abs(a);
}


long int lcm(const int a, const int b)
{
	if ((a >= 1 && a <= 10000) && (b >= 1 && b <= 10000))
	{
		return a * b / NSD(a, b);
	}
	return -1;
}


int main(void)
{
	return 0;
}




