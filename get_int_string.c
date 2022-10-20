#include "monty.h"
/**
 * get_int - gets opcode <int> from @str
 * @str: a string
 *
 * Return: an integer
 */

int get_int(char *str)
{
	int len = strlen(str), j = 0, i = 0, integer = 0;
	char *arr = malloc(len * sizeof(char));

	if (!arr)
		monty_error_malloc_free("Error: malloc failed", str);
	for (i = 0; i < len; i++)
	{
		if (str[i] >= 46 && str[i] <= 57)
		{
			arr[j] = str[i];
			j++;
			if (str[i + 1] == ' ')
				break;
		}
	}
	arr[j] = '\n';
	integer += atoi(arr);
	free(arr);
	return (integer);
}

/**
 * get_string - gets opcode <string> from @str
 * @str: a string
 *
 * Return: a string
 */

char *get_string(char *str)
{
	int len = strlen(str);
	int j = 0, i = 0;
	char *arr = malloc(len * sizeof(char));

	if (!arr)
		monty_error_malloc_free("Error: malloc failed", str);
	for (i = 0; i < len; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			arr[j] = str[i];
			j++;
			if (str[i + 1] == ' ')
				break;
		}
	}
	arr[j] = '\0';
	strcpy(str, arr);
	free(arr);
	return (str);
}

/**
 * isdigit - check if @number is a digit
 * @number: an integer
 * Return: int
 */

int isdigit(int number)
{
	if (number >= -9999999 && number <= 99999999)
	{
		return (1);
	}
	return (0);
}
