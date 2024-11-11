/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prinft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:20:50 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/11 17:26:01 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int print_char(int c)
{
	return (write(1, &c,1));
}
int print_str(char *str)
{
	int count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while(*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}
int print_digit(unsigned long  n, unsigned  base, char specifier)
{
	int count;
	char *symbols;
	if (specifier == 'x' || specifier == 'p')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		if (specifier != 'u')
			write(1, "-",1);
		return (print_digit(-n,base, specifier) + 1);
	}
	else if (n < base)
		return print_char(symbols[n]);
	else 
	{
		count = print_digit(n / base, base, specifier);
		return count + print_digit(n % base, base, specifier);
	}
}

int print_format(char specifier, va_list args)
{
	int count;
	count  = 0;
	
	if(specifier == 'c')
		count += print_char(va_arg(args,int));
	else if (specifier == 's')
		count += print_str(va_arg(args,char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(args, int)), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		count += print_digit((long)(va_arg(args, unsigned int)), 16, specifier);
	else if (specifier == 'p')
	{
		write(1, "0x",2);
		count += print_digit(( unsigned long )(va_arg(args, unsigned long int)),16,specifier) + 2;
	}
	else if (specifier == 'u')
		count += print_digit(va_arg(args, unsigned int), 10, specifier);
	else
		count += write(1, &specifier,1);
	return (count);
	
}
int ft_printf(const char *str, ...)
{
	int count;
	va_list args;
	va_start(args,str);
	count  = 0;
	if (!str)
		return (-1);
	while(*str)
	{
		if(*str == '%')
			count += print_format(*(++str),args);
		else 
			count += write(1, str,1);
		++str;
	}
	va_end(args);
	return(count);
}
