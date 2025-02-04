#ifndef P
#define P
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *format, ...);

int (*get_fs_function(char s))(va_list);

/**
 * struct pf - Struct printf
 *
 * @format_specifier: s c i d
 * @funcpoint: The function associated
 */
typedef struct pf
{
char *format_specifier;
int (*funcpoint)(va_list);
} print_fs;

int print_char(va_list);

int print_string(va_list);

int print_i_d(va_list);

int _putchar(char c);

#endif

