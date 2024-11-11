/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:57:03 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/11 20:14:04 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_print_adress(unsigned long n, int base)
{
	char *symbols;
	int count;

	count  = 0;
	symbols  = "0123456789abcdef";
	if(n < base)
	{
		return ft_putchar(symbols[n]);
	}else
	{
		count  = ft_print_adress(n / base,base);
		return count + ft_print_adress(n % base, base);
	}
}
