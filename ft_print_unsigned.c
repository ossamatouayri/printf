/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:24:33 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/12 13:24:16 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unsigned(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < base)
	{
		return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_print_unsigned(n / base, base);
		return (count + ft_print_unsigned(n % base, base));
	}
}
