#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "main.h"

/* state */
/* 0 is regular */
/* 1 is escape */

/**
 * v_printf - performs the print function in a formatted way
 * @fmt: first argument, the format
 * @args: second argument, the list of argument variables
 *
 * Return: void
 */

void v_printf(const char *fmt, va_list args)
{
	int state = 0, is_long = 0, can_reset = 1;
	char number_buffer[65];

	while (*fmt)
	{
		if (state == 0)
		{
			if (*fmt == '%')
				state = 1;
			else
				putchar(*fmt);
		}
		else if (state == 1)
		{
			switch (*fmt)
			{
				case 'c':
					{
						char ch = va_arg(args, int);

						putchar(ch);
						break;
					}
				case 's':
					{
						const char *s = va_arg(args, const char *);

						while (*s)
							putchar(*s++);
						break;
					}
			}
			fmt++;
		}
	}
}

/**
 * _printf - the real printing function
 * @fmt: first argument
 * @...: ellipses
 *
 * Return: void
 */

int _printf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	v_printf(fmt, args);
	va_end(args);
	int i = 0, j = 0;

	while (*fmt++)
	{
		if (*fmt == '%')
		{
			if (*fmt == *(fmt + 1))
			{
				j++;
			}
		}
		else
		{
			i++;
		}
	}
	if (j == 0)
		return (i);
	else
		return (i + j);
}
