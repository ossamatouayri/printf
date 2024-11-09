/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prinft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:20:50 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/09 21:45:55 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int print_format(char specifier, va_list args)
{
	int count;
	count  = 0;
	
	if(specifier == 'c')
		count += printf_char(va_arg(args,int));
	else if (specifier == 's')
		count += print_str(va_arg(args,char *));
	else if (specifier == 'd')
		count += print_digit((va_arg(args,int)));
	else if (specifier == 'x')
		
}
int ft_printf(const char *str, ...)
{
	int count;
	va_list args;
	va_start(args,str);
	va_arg(args,char *);
	count  = 0;
	while(*str)
	{
		if(*str == '%')
			count += printf_format(*(++str),args);
		else 
			count += write(1, str,1);
		++str;
	}
	va_end(args);
	return(count);
}
int main()
{
	int count = ft_printf("Hello %s\n","Oussama");
	ft_printf("%d\n",count);
}
