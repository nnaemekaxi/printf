#include "main.h"
#include <unistd.h>

/**
 * _putchar - function writes the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 * Description: _putchar uses a local buffer of 1024 to call write
 * as little as possible
 */

int _putchar(char ch)
{
	static char buffer[1024];
	static int iter;

	if (ch == -1 || iter >= 1024)
	{
		write(1, &buffer, iter);
		iter = 0;
	}
	if (ch != -1)
	{
		buffer[iter] = ch;
		iter++;
	}
	return (1);
}

/**
 * _puts - function prints a string to stdout
 * @strng: pointer to the string to print
 *
 * Return: number of chars written
 */

int _puts(char *strng)
{
	register int iter;

	iter = 0;
	while (strng[iter] != '\0')
	{
		_putchar(strng[iter]);
	iter++;
	}
	return (iter);
}
