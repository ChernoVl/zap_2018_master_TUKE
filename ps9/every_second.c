#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void work(char *name);
void seek_S_F(FILE *fp, unsigned int *start, unsigned int *finish);
int assimilation(char *ch1, char *ch2);
int lenght_str(char *str);

int main(int argc, char *argv[])
{	//argc – argument count, или “счётчик аргументов”;
	//argv – argument vector, или “вектор аргументов”.
//	argv[1] = "input.txt";
	work(argv[1]);
	//fp = fopen(argv[1], "w");
	//char* ch = intINchar(k);
	//outputf(fp, ch);
	//fclose(fp);
//	system("pause");
	return 0;
}

void work(char *name)
{
	FILE *fp = fopen(name, "r");
	unsigned int start;
	unsigned int finish;
	char ch;
	int i, k;
	seek_S_F(fp, &start, &finish);
	fclose(fp);
	fp = fopen(name, "r");
	i = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (i++ == start)
		{
			break;
		}
	}
	i--;
	k = 0;
	FILE *fout = fopen("output.txt", "w");
	while ((ch = fgetc(fp)) != EOF && i++ != finish)
	{
		if (ch == ' ')
		{
			k++;
		}
		if (k % 2 && !(k == 1 && ch == ' '))
		{
			fputc(ch, fout);
		}
	}
	fclose(fp);
	fclose(fout);
}

void seek_S_F(FILE *fp, unsigned int *start, unsigned int *finish)
{
	char ch;
	char st[6];
	const unsigned short int s = 5;
	int i = 0;
	int ind = 0;
	(*start) = 0;
	(*finish) = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		ind++;
		if (ch != ' ' && i < s)
		{
			st[i++] = ch;
		}
		else
		{
			st[i] = '\0';
			if (assimilation(st, "START"))
			{
				while ((ch = fgetc(fp)) != EOF && ch == ' ')
					i++;
				(*start) = ind;
				break;
			}
			else
			{
				i = 0;
			}
		}
	}
	i = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		ind++;
		if (ch != ' ' && i < s)
		{
			st[i++] = ch;
		}
		else
		{
			st[i] = '\0';
			if (assimilation(st, "STOP"))
			{
				(*finish) = ind - 6;
				break;
			}
			else
			{
				i = 0;
			}
		}
	}
	if (!(*finish))
	{
		(*finish) = ind - 5;
	}
}

int assimilation(char *ch1, char *ch2)
{
	if (lenght_str(ch1) != lenght_str(ch2))
	{
		return 0;
	}
	else
	{
		for (int i = 0; ch1[i] != '\0'; i++)
		{
			if (ch1[i] != ch2[i])
			{
				return 0;
			}
		}
	}
	return 1;
}

int lenght_str(char *str)
{
	int k = 0;
	while (str[k++] != '\0');
	return --k;
}