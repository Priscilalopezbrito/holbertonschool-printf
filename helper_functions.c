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
 * Return: length char
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
	int div = 1;
	int temp;/*used to save num value*/
	int min_uf = 0;/*use to handle INT_MIN special case*/

	if (num < 0)/*negative numbers case*/
	{
		_putchar('-');/*minus char*/
		counter++;
		if (num == INT_MIN)/*prevent underflow*/
		{
			num = -(num + 1);/*-2147483647 - 1*/
			min_uf = 1;
		}
		else
		{
			num = -num;/*if not min just print - num*/
		}
	}
	temp = num;/*store value  in temp*/
	/*size*/
	while (temp / div >= 10)/*if num 10 or bigger*/
	{
		div = div * 10;/*1 * 10*/
	}
	while (div != 0)/*print number*/
	{
	int digit = num / div;/*current number to print*/
/*modify last number from -2147483647 to -2147483648 */
	if (min_uf && div == 1)
	{
		digit++;
	}
	_putchar('0' + digit);/*converts int to ASCII char*/
	num = num % div;/*987 87 7*/
	div = div / 10;/*1000 100 10*/
	counter++;/*increment count*/
	}
return (counter);/*count*/
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
