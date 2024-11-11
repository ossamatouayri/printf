/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:08:57 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/11 21:26:03 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_print_format(char specifier, va_list args)
{
	int count;

	count  = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
	{
		write(1, "0x", 2);
		count += ft_print_adress((unsigned long)(va_arg(args, unsigned long)), 16) + 2;
	}
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr((long)(va_arg(args, int)), 10);
	return (count);
}
int ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args,str);
	int count;
	
	count  = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_print_format(*(++str), args);
		}
		else
			count += write(1, str, 1);
		++str;
	}
	return (count);
}
int main (){
	int *p;
	int count  = printf("salam %d\n",500);
	int hsab  = ft_printf("salam %d\n",500);
	printf("%d %d\n",count ,hsab);
}
