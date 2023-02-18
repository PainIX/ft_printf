/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:29 by armartir          #+#    #+#             */
/*   Updated: 2023/01/25 15:04:20 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
	{
		return (write (1, "(null)", 6));
	}
	i = 0;
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int num)
{
	int	i;

	i = 1;
	if (num == -2147483648)
	{
		i += write(1, "-2147483648", 11) - 1;
		return (i);
	}
	if (num < 0)
	{
		i += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		i += ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
	return (i);
}

unsigned int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 1;
	if (n >= 10)
		i += ft_putnbr_u(n / 10);
	ft_putchar(n % 10 + '0');
	return (i);
}
