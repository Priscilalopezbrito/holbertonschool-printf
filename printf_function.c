#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - Function produce output according to format
 *@format: Character string
 *Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count;

	count = 0;
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				_putchar('%');
				count++;
				va_end(args);
				return (count);
			}
			else if (format[i] == '%')
			{
				count = count + _putchar('%');
			}
			else
			{
				/*calling get_op_function to evaluate format specifier*/
				int (*funcpoint)(va_list) = get_fs_function(format[i]);

				if (funcpoint == NULL)/*{NULL, NULL}*/
				{
					count = count + _putchar('%');
					count = count + _putchar(format[i]);/**/
				}
				else
					count = count + funcpoint(args);/**/
			} /*Ends condition, if char is not fount in struct array...*/
		} else
				count = count + _putchar(format[i]);
	} /*Ends for loop scope */
	va_end(args);
	return (count);/*Returns: the number of characters printed*/
}

