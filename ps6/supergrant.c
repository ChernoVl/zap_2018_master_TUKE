#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(const int number);// - Проверка, является ли число number простым(prime number).
int next_prime(const int prime);// - Найти на основе найденного просто числа prime следующее простое число.
int NextPrime(int *prime);
long int find_A_n(const int n);// - На основе данного числа n найти A_n.
int sum_digits(const long int number);// - Найти сумму цифр числа number.
int sum_digits_n(const int n);// - На основе данного числа n найти n - ное число в последовательности циферной суммы.
int constant(const int a, const int b);// - Найти константу K супергранта.

int main(){
	int a, b, necessary;
	scanf("%d%d%d", &a, &b, &necessary);
	if (a >= 1			 && a <= 5000 && 
		b >= -20		 && b <= 20 && 
		necessary >= 1e3 && necessary <= 1e6)
	{
		printf("Supergrant: %.2f\n", necessary*(1. - ((double)constant(a, b)) / 100));
		return 0;
	}
	printf("Wrong input!\n");
	return 1;
}


int is_prime(const int number)
{
	if (number == 2)
	{
		return 1;
	}
	else if (number == 1 || !(number % 2))
	{
		return 0;
	}
	for (int i = 3; i <= number / 2; i += 2)
	{
		if (!(number%i))
		{
			return 0;
		}
	}
	return 1;
}

int next_prime(const int prime)
{
	if (prime == 2)
	{
		return prime + 1;
	}
	if (is_prime(prime))
	{
		for (int i = prime + 2;; i += 2)
		{
			if (is_prime(i))
			{
				return i;
			}
		}
	}
	return -1;
}

long int find_A_n(const int n)
{
	int j = 0;
	int p_i = 0;
	if (n >= 1)
	{
		int A_n = 3;		
		while (1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (A_n % p_i == i)
				{
					NextPrime(&p_i);
					j++;
				}
				if (j == n)
				{
					return A_n;
				}
			}
			NextPrime(&A_n);
			p_i = 2;
			j = 0;
		}
	}
	p_i = j + 2;
	j = p_i + 4;
	return 0;
}

int NextPrime(int *prime)
{
	if (*prime == 2)
	{
		return ++(*prime);
	}
	if (is_prime(*prime))
	{
		for (int i = (*prime) + 2;; i += 2)
		{
			if (is_prime(i))
			{
				(*prime) = i;
				return i;
			}
		}
	}
	return -1;
}

int sum_digits(const long int number)
{
	if (number > 0)
	{
		return number % 10 + sum_digits(number / 10);
	}
	return 0;
}

int sum_digits_n(const int n)
{
	if (n > 0)
	{
		if (n == 1 || n == 2)
		{
			return 1;
		}
		int sum = 2;
		int last_sum;
		for (int i = 4; i <= n; i++)
		{
			last_sum = sum_digits(sum);
			sum += last_sum;	
		}
		return sum;
	}
	return 0;
}

int constant(const int a, const int b)
{
	int abc = sum_digits_n(a);
	int y, K;
	if (b >= 1 && b <= 9)
	{
		y = sum_digits(find_A_n(b));
	}
	else
	{
		y = sum_digits(sum_digits_n(a));
	}
	if (y > abc)
	{
		K = y / abc;
	}
	else
	{
		K = abc / y;
	}
	if (K <= 49)
	{
		return K;
	}
	else if (!(K % 2))
	{
		while (K >= 50)
		{
			K /=2;
		}
	}
	else
	{
		while (K >= 50)
		{
			K = sum_digits(K);
		}
	}
	return K;
}