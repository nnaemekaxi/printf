#include "main.h"
/**
 * _printf - printf function prints data to stdout
 * @format: pointer to const char
 * Return: no. of chars printed out
 */

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *ptr;
	va_list list;
	flags_t flags = {0, 0, 0};

	register int ret_val = 0;

	va_start(list, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '%')
			{
				ret_val += _putchar('%');
				continue;
			}
			while (get_flag(*ptr, &flags))
				ptr++;
			pfunc = get_print(*ptr);
			ret_val += (pfunc)
				? pfunc(list, &flags)
				: _printf("%%%c", *ptr);
		} else
			ret_val += _putchar(*ptr);
	}
	_putchar(-1);
	va_end(list);
	return (ret_val);
}
