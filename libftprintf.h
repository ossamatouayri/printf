/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:20:52 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/11 21:27:09 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF
#define LIBFT_PRINTF

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *, ...);
int ft_putchar(int c);
int ft_putstr(char *str);
int ft_print_adress(unsigned long n,int base);
int ft_putnbr(long n, int base);

#endif
