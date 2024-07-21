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

	return (_putchar(_char)); /*count is always 1 */
}

/**
 * print_string- handle string
 * @args: va list
 * Return: number of char
 */
int print_string(va_list args)/*count char */
{
	char *_string = va_arg(args, char *);
	int le = 0;/*le used to count length*/

	if (_string == NULL)/*if string is null print (null)*/
	{
		_string = "(null)";
	}

	while (_string[le] != '\0')/*returns number of char*/
	{
		_putchar(_string[le]);
		le++;
	}
	return (le);
}

/**
 * print_i_d- handle %i %d
 * @args: va list
 * Return: number of char
 */
int print_i_d(va_list args)
{
	int num = va_arg(args, int);
	int counter = 0;/*count*/
	int div = 1;/*divisor*/
	int temp;/*store num info*/

	if (num < 0)/*handle negative numbers*/
	{
		_putchar('-'); /*Print '-' sign*/
		counter++;
		if (num == INT_MIN)/*-2147483647 - 1*/
		{
			num = -(num + 1); /* Convert to + and add 1 for overflow*/
			temp = num;/*stores num in temp*/
			while (temp >= 10)/*check divisor to determine length*/
			{
				temp = temp / 10;/*10/10 = 1*/
				div = div * 10;/* 1 * 10 = 10*/
			}
			while (div != 0)/*prints digits 64-76*/
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
			num = -num; /*number = -number*/
	}
	temp = num;
	while (temp >= 10)/**/
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
