#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/*
 *_printf- Function produce output according to format
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
		
		if (format[i] == '%')/*if % is found*/
		{
			/*Handles if % is followed by char %. Example:%% */
			if (format[i] == '%' && format[i + 1] == '%')
			{
				count = count + _putchar('%');/*print %*/
				i = i + 2;/* % % _ */
			}
			if (format[i + 1] != '\0')/* if % + 1 is not \0 */
			{
				/*calling get_op_function to evaluate format specifier*/
				int (*funcpoint)(va_list) = get_op_function(format[i + 1]);
				if (funcpoint == NULL)/*{NULL, NULL}*/
				{
					count = count + _putchar(format[i]);/**/
				}
				else
				{
					count = count + funcpoint(args);/**/
					i++;
				}
			}/*Ends condition, if char is not fount in struct array...*/
			else
			{
				count = count + _putchar('%');
			}
		}/*Ends if format == % condition.*/
		
		else/**/
		{
			count = count + _putchar(format[i]);
		}
	}/*Ends for loop scope */
	va_end(args);
	return (count);/*Returns: the number of characters printed*/
}
