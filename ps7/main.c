#include "hangman.h"
#include <malloc.h>
#include <stdio.h>

int main()
{
	char *secret = (char*)malloc(15 * sizeof(char*));
	get_word(secret);
	hangman(secret);
	free(secret);
	return 0;
}