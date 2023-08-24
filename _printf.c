#include "main.h"
#include <stdio.h>
#include <stdarg.h>
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
  /*	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;*/
	va_list list;
	/* char buffer[BUFF_SIZE];*/
	
	/*c and *s specifiers */
	int i, c;
	char *s;
	if (format == NULL)
		return (-1);

	va_start(list, format);

	/** Your Code in red:
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			 write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
	} */
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

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
