#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *print_char- executes char
 *@args: va list
 *Return: number of char
 */
int  print_char(va_list args)
{
	char _char = va_arg(args, int);
	return (_putchar(_char));/*count siempre sera 1*/
}


/*
 *print_string- handle string
 *@args: va list
 *Return: number of char
 */
int  print_string(va_list args)/*cantidad dentro de char */
{
	char * _string = va_arg(args, char *);
	int le = 0;/*used to count*/

	while (_string[le] != '\0')
	{
		_putchar( _string[le]);
		le++;
		
	}
	return (le);/*returns number of char*/
}


/*
 *print_int- handle int
 *@args: va list
 *Return: number of char
 */
int print_i_d(va_list args)
{

	int max = 2147483647;
	int min = -2147483647 - 1;
	int num = va_arg(args, int);
	int counter = 0;
	int divisor = 1;
	int temp = num;

	/*handle numbers that excedes limits*/
   if (num < min || num > max)
	{
		return (-1);
	}
	/*Condition to handle
	 * negative numbers
	 */
	if (num < 0)
	{
		_putchar('-');/*Print char -*/
		num = -num;
		counter++;
	}
	while (temp >= 10 || temp <= -10)
	{
		temp = temp / 10;/*extract last digit*/
		divisor = divisor /* 10;*10 100 1000 10000*/
	}
	while (divisor != 0)
	{
		int digit = num / divisor;

		_putchar('0' + digit);
		num = num % divisor;
		divisor = divisor / 10;
		counter++;
	}
	return counter;
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
