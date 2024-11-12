/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:18:57 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/12 13:41:12 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n, base) + 1);
	}
	else if (n < base)
	{
		return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_putnbr(n / base, base);
		return (count + ft_putnbr(n % base, base));
	}
}
