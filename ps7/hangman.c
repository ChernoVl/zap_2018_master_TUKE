#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <malloc.h>
#include <string.h>

//отримаэмо рандомне слово
int get_word(char secret[])
{
	// check if file exists first and is readable
	FILE *fp = fopen(WORDLIST_FILENAME, "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME); ///WORDLIST_FILENAME = "words.txt"
		return 1;
	}

	// get the filesize first
	struct stat st;
	stat(WORDLIST_FILENAME, &st);
	long int size = st.st_size;

	do {
		// generate random number between 0 and filesize
		long int random = (rand() % size) + 1;
		// seek to the random position of file
		fseek(fp, random, SEEK_SET);
		// get next word in row ;)
		int result = fscanf(fp, "%*s %20s", secret); // result - результат роботи ф-ї fscanf()
		if (result != EOF)
			break;
	} while (1);

	fclose(fp);

	return 0;
}
//Повертає 1 якшо слово угадане
int is_word_guessed(const char secret[], const char letters_guessed[])
{
	int k = 0;
	int i;
	for (i = 0; secret[i] != '\0'; i++)
	{
		for (int j = 0; letters_guessed[j] != '\0'; j++)
		{
			if (secret[i] == letters_guessed[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
	{
		return 1;
	}
	return 0;
}
//в масив записує угадані букви з _
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[])
{
	int k;
	for (int i = 0;; i++)
	{
		//Виxід з циклу
		if (secret[i] == '\0')
		{
			guessed_word[i] = '\0';
			break;
		}
		k = 0;
		for (int j = 0; letters_guessed[j] != '\0'; j++)
		{
			if (secret[i] == letters_guessed[j] || secret[i] == letters_guessed[j] + 32)
			{
				k++;
				break;
			}
		}
		if (k)
		{
			guessed_word[i] = secret[i];
		}
		else
		{
			guessed_word[i] = '_';
		}
	}
}
//з алфавіту убира використані букви
void get_available_letters(const char letters_guessed[], char available_letters[])
{
	char ABC[] = { "abcdefghijklmnopqrstuvwxyz" };
	int q = 0;
	int k;
	for (int i = 0; ABC[i] != '\0'; i++)
	{
		k = 0;
		for (int j = 0; letters_guessed[j] != '\0'; j++)
		{
			if (ABC[i] == letters_guessed[j])
			{
				k++;
				break;
			}
		}
		if (!k)
		{
			available_letters[q++] = ABC[i];
		}
	}
	available_letters[q] = '\0';
}

void dell(char ch[], int index)
{
	int i;
	for (i = index; ch[i+1] != '\0'; i++)
	{
		ch[i] = ch[i + 1];
	}
	ch[i] = '\0';
}

int guessed_letters(char guessed_word[])
{
	int k = 0;
	char *guessed = (char*)malloc(15 * sizeof(char*));
	for (int i = 0; guessed_word[i] != '\0'; i++)
	{
		if (guessed_word[i] != '_' && guessed_word[i] != '\0')
		{
			guessed[k++] = guessed_word[i];
		}
	}
	guessed[k] = '\0';
	for (int i = 0; guessed[i] != '\0'; i++)
	{
		for (int j = i + 1; guessed[j] != '\0'; j++)
		{
			if (guessed[i] == guessed[j] && guessed[i] >= 'a' && guessed[i] <= 'z')
			{
				dell(guessed, j);
				j--;
			}
		}
	}
	k = 0;
	for (int i = 0; guessed[i] != '\0'; i++)
	{
		k++;
	}
	free(guessed);
	return k;
}

void pr(char guessed_word[])
{
	for (int i = 0; guessed_word[i] != '\0'; i++)
	{
		printf(" %c", guessed_word[i]);
	}
	printf("\n");
}

int clone(char letters_guessed[], char ch)
{
	for (int i = 0; letters_guessed[i] != '\0'; i++)
	{
		if (ch == letters_guessed[i])
		{
			return 1;
		}
	}
	return 0;
}

void registr(char *ch)
{
	if ((*ch) >= 'A' && (*ch) <= 'Z')
	{
		(*ch) += 32;
	}
}

void hangman(const char secret[])
{
	/*
		secret[] - Строка, що представляє секретне слово
		letters_guessed[] - Строка з усіма досі вгаданими літерами
		guessed_word[] - Вихідний параметр функції, який буде представляти ланцюжок вгаданого слова
		available_letters[] - Мережа алфавіту, крім вгаданих букв. Вихідний параметр функції
	*/
	int attempt = 8;
	char *letters_guessed = NULL;
	letters_guessed = (char*)malloc((15 + 8) * sizeof(char*));
	char *available_letters = (char*)malloc(27 * sizeof(char*));
	char *guessed_word = (char*)malloc(strlen(secret) * sizeof(char*));
	get_guessed_word(secret, letters_guessed, guessed_word);
	printf("Welcome to the game, Hangman!\n");
	printf("I am thinking of a word that is %ld letters long.\n", strlen(secret));
	get_available_letters(letters_guessed, available_letters);

	int index = guessed_letters(guessed_word);
	int r = 0;
	char ch = ' ';
	char symbol = ' ';
	for (int i = 0; attempt && !is_word_guessed(secret, letters_guessed);)
	{
		printf("-------------\n");
		printf("You have %d guesses left.\n", attempt);
		printf("Available letters: %s\n", available_letters);
		printf("Please guess a letter: ");
		r = 0;
		while (1)
		{
			scanf("%c", &ch);
			registr(&ch);
			if (ch != '\n' && i < (15 + 8))
			{
				if (ch >= 'a' && ch <= 'z' && (!clone(letters_guessed, ch) || r > 0))
				{
					letters_guessed[i++] = ch;
					symbol = ch;
					r++;
				}
				else//якшо символ або буква яка вже була введена
					if (clone(letters_guessed, ch) && r < 2)
					{
						symbol = ' ';
						printf("Oops! You've already guessed that letter:");
						pr(guessed_word);
					}
					else if (r < 2)
					{
						symbol = ch;
						printf("Oops! '%c' is not a valid letter:", ch);
						pr(guessed_word);
					}
			}
			else
			{
				break;
			}
		}
		if (r > 1)
		{
			break;
		}
		get_guessed_word(secret, letters_guessed, guessed_word); //в масив записує угадані букви з _
		get_available_letters(letters_guessed, available_letters); //з алфавіту убира використані букви

		if (guessed_letters(guessed_word) > index)
		{
			index++;
			printf("Good guess:");
			pr(guessed_word);
		}
		else if (symbol >= 'a' && symbol <= 'z')
		{
			printf("Oops! That letter is not in my word:");
			pr(guessed_word);
			attempt--;
		}

	}
	if (is_word_guessed(secret, letters_guessed))
	{
		if (r < 2)
		{
			printf("-------------\n");
		}
		printf("Congratulations, you won!\n");
	}
	else
	{
		printf("-------------\n");
		printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
	}

	free(letters_guessed);
	free(guessed_word);
	free(available_letters);
}