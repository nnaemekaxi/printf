#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */

int get_flag(char s, flags_t *f)
{
	int x = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			x = 1;
			break;
		case ' ':
			f->space = 1;
			x = 1;
			break;
		case '#':
			f->hash = 1;
			x = 1;
			break;
	}
	return (x);
}
/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @f: the parameters struct
 *
 * Return: if modifier was valid
 */

int get_modifier(char *s, flags_t *f)
{
	int x = 0;

	switch (*s)
	{
	case 'h':
		x = f->h_modifier = 1;
		break;
	case 'l':
		x = f->l_modifier = 1;
		break;
	}
	return (x);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @f: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */

char *get_width(char *s, flags_t *f, va_list list)
/* should this function use char **s and modify the pointer? */
{
	int y = 0;

	if (*s == '*')
	{
		y = va_arg(list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			y = y * 10 + (*s++ - '0');
	}
	f->width = y;
	return (s);
}
