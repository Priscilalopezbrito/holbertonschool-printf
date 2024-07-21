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

	if (_string[le] != '\0')
	{
		_putchar(_string[le]);
		le++;
	}
	else
	{
		return ('\0');
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

	int max = INT_MAX;
	int min = INT_MIN;
	int num = va_arg(args, int);
	int counter = 0;
	int div = 1;
	int temp = num;
	

	/*
	 * Condition to handle
	 * negative numbers
	 */
	if (num < 0)
	{
		_putchar('-');/*Print char -*/
		num = -num;
		counter++;
	}
	if (num < min || num > max)
	{
		return (-1);
	}
	/*
	 * Extract and print digits
	 *numbers equal or larger
	 *than 10 or equal or smaller
	 *than -10
	 */
	while (temp >= 10 || temp <= -10)
	{
		temp = temp / 10;/*extract last digit*/
		div = div * 10;/*10 100 1000 10000*/
	}
	while (div != 0)/*while divisor is not 0*/
	{
		int digit;

		digit = num / div; /*gets first num ->1 23 */
		_putchar('0' + digit);/*digit is printed 1 */
		num = num % div;/*extract first example 123 to 23*/
		div = div / 10;/*1000 100 10*/
		counter++;/*increment*/
	}
	return (counter);/*number of digits*/
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
