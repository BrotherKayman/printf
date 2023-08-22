#include "main.h"
#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...)
{
va_list spec;

int dgtCount = 0;
char c;
char *s;
unsigned int i, d;
unsigned int temp;
char formatStr;
va_start(spec, format);
int x = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
c = va_arg(spec, int);
_putchar(c);
x++;
break;
}
case 's':
{
*s = va_arg(spec, char *);
while (*s != '\0')
{
_putchar(*s);
s++;
x++;
}
break;
}
case 'd':
{
d = va_arg(spec, unsigned int);
temp = d;
// Count the number of digits in the number
do
  {
temp /= 10;
dgtCount++;
}
 while (temp != 0);
// Create a format string with width for padding
formatStr[10]; // Assuming digits < 10
snprintf(formatStr, sizeof(formatStr), "%%%uu", dgtCount);
// Print the unsigned int using the formatted string
x += _printf(formatStr, d);
break;
}
case 'i':
  { // Handle signed int
i = va_arg(spec, unsigned int);
dgtCount = 0;
temp = i;
// Count the number of digits in the number
do
{
temp /= 10;
dgtCount++;
}
while (temp != 0);
// Create a format string with width for padding
formatStr[10]; // Assuming digits < 10
snprintf(formatStr, sizeof(formatStr), "%%%uu", dgtCount);
// Print the unsigned int using the formatted string
x += printf(formatStr, i);
break;
}
case '%':
  {
_putchar('%');
x++;
break;
}
default:
  {
_putchar('%');
_putchar(*format);
x += 2;
break;
}
}
} else
  {
_putchar(*format);
x++;
}
format++;
}
va_end(spec);
return (x);
}
