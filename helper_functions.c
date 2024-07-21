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
	int counter = 0;
	int div = 1;
	int temp;
	int min_uf = 0;

	if (num < 0)
	{
		_putchar('-');
		counter++;
		if (num == INT_MIN)
		{
			num = -(num + 1);
			min_uf = 1;
		}
		else
		{
			num = -num;
		}
	}
	temp = num;
	while (temp / div >= 10)
	{
		div *= 10;
	}
	while (div != 0)
	{
	int digit = num / div;

	if (min_uf && div == 1)
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
