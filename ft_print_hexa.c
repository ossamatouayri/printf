/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:41:26 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/12 21:23:04 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(long n, int base, char specifier)
{
	int		count;
	char	*symbols;

	count = 0;
	if (specifier == 'x')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < base)
	{
		return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_print_hexa(n / base, base, specifier);
		return (count + ft_print_hexa(n % base, base, specifier));
	}
}
