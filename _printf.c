#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, c;
	char *s;
	if (format == NULL)
		return (-1);

	va_start(list, format);
	/* Printing c and s without flags and buffers */
	for (i = 0; format[i] != '\0'; i++)
	  {
	  if (format[i] == '%' && format[i + 1] != '\0')
	    {
	    i++;
	    switch (format[i])
	      {
	    case 'c':
	      {
	     c = va_arg(list, int);
	      putchar(c);
	      break;
	    }
	    case 's':
	      {
	       s = va_arg(list, char *);
	      fputs(s, stdout);
	      break;
	    }
	    default:
	      putchar('%');
	      putchar(format[i]);
	      break;
	    }
	  } else {
	    putchar(format[i]);
	  }
	}


	va_end(list);
	return (i);
}
