#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void registr(char *ch);
char* intINchar(int a);
int ananas_in_word(char *masch);
void outputf(FILE *fp, char *ch);
int inputf(FILE *fp);

int main(int argc, char *argv[])
{	//argc – argument count, или “счётчик аргументов”;
	//argv – argument vector, или “вектор аргументов”.
	//argv[1] = "bananas2.txt";
	FILE *fp = fopen(argv[1], "r");
	int k = inputf(fp);
	fclose(fp);
	fp = fopen(argv[1], "w");
	char* ch = intINchar(k);
	outputf(fp, ch);
	fclose(fp);
	//system("pause");
	return 0;
}

void registr(char *ch)
{
	if ((*ch) >= 'A' && (*ch) <= 'Z')
	{
		(*ch) += 32;
	}
}

int ananas_in_word(char *masch)
{
	char ananas[] = "ananas";
	int ind;
	for (int i = 0; masch[i] != '\0'; i++)
	{
		ind = 0;
		for (int j = 0; ananas[j] != '\0'; j++)
		{
			if (masch[j + i] == ananas[j])
			{
				ind++;
			}
			else
			{
				break;
			}
			if (ind == 6)
			{
				return 1;
			}
		}
	}
	return 0;
}

char* intINchar(int a)
{
	char *ch = (char *)malloc(10 * sizeof(char));
	int v = 0; //количество цифр в числе a
	//разбиваем на отдельные символы число a
	while (a > 9)
	{
		ch[v++] = (a % 10) + '0';
		a = a / 10;
	}
	ch[v++] = a + '0';
	ch[v] = '\0';
	char t;
	//инвертируем массив символов
	for (int i = 0; i < v / 2; i++)
	{
		t = ch[i];
		ch[i] = ch[v - 1 - i];
		ch[v - 1 - i] = t;
	}
	return ch;
}

void outputf(FILE *fp, char *ch)
{
	for (int i = 0; ch[i] != '\0'; i++)
	{
		fputc(ch[i], fp);
	}
}

int inputf(FILE *fp)
{
	char *ananas = (char*)malloc(20 * sizeof(char));
	int k = 0, i = 0;
	char ch;
	while ((ch = fgetc(fp)) != EOF)
	{
		registr(&ch);
		if (ch != ' ')
		{
			ananas[i++] = ch;
		}
		else
		{
			ananas[i] = '\0';
			if (ananas_in_word(ananas))
			{
				k++;
			}
			i = 0;
		}
	}
	ananas[i] = '\0';
	if (ananas_in_word(ananas))
	{
		k++;
	}
	free(ananas);
	return k;
}