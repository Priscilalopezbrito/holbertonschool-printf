#include "main.h"
#include <stdio.h>
#include <limits.h>
/**
 * print_char- executes char
 * @args: va list
 * Return: number of char
 */
int print_char(va_list args)
{
	char _char = va_arg(args, int);

	return (_putchar(_char)); /*count siempre sera 1*/
}

/**
 * print_string- handle string
 * @args: va list
 * Return: number of char
 */
int print_string(va_list args)/*cantidad dentro de char */
{
	char *_string = va_arg(args, char *);
	int le = 0;/*used to count*/

	if (_string == NULL)
	{
		_string = "(null)";
	}

	while (_string[le] != '\0')
	{
		_putchar(_string[le]);
		le++;
	}
	return (le);/*returns number of char*/
}

/**
 * print_i_d- handle %i %d
 * @args: va list
 * Return: number of char
 */
int print_i_d(va_list args)
{
	int num = va_arg(args, int);
	int counter = 0;
	int div = 1;
	int temp;

	if (num < 0)/*-numbers*/
	{
		_putchar('-'); /*Print - sign*/
		counter++;
		if (num == INT_MIN)
		{
			num = -(num + 1); /* Convert to + and add 1 for overflow*/
			temp = num;
			while (temp >= 10)/*check divisor*/
			{
				temp = temp / 10;
				div = div * 10;
			}
			while (div != 0)/*prints digits*/
			{
				int digit = num / div;

				if (div == 1)/*last num print correct*/
				{
					digit++;
				}
				_putchar('0' + digit);
				num = num % div;
				div = div / 10;
				counter++;
			}
			return (counter);
		}
		else
			num = -num; /* Convert to positive*/
	}
	temp = num;
	while (temp >= 10)/*divisor*/
	{
		temp = temp / 10;
		div = div * 10;
	}
	while (div != 0)/*print digit 1 by 1*/
	{
		int digit = num / div;

		_putchar('0' + digit);
		num = num % div;
		div = div / 10;
		counter++;
	}
	return (counter); /* Number of digits printed*/
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
