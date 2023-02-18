/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:56 by armartir          #+#    #+#             */
/*   Updated: 2023/02/09 17:25:24 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_utils(int c, unsigned long long tmp, char x)
{
	char	*hex;
	int		len;
	char	*str;

	str = (char *)malloc(sizeof(char) * (c));
	if (!str)
		return (0);
	len = 0;
	if (x == 'x' || x == 'p')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	str[c] = '\0';
	while (--c != -1)
	{
		str[c] = hex[tmp % 16];
		tmp /= 16;
	}
	while (str[++c] == '0')
		;
	while (str[c])
		len += ft_putchar(str[c++]);
	free (str);
	return (len);
}

int	hex(unsigned long long n, char x)
{
	unsigned long long	tmp;
	int					count;

	tmp = (unsigned long long)n;
	count = 1;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		count++;
	}
	if (n != 0)
		count = hex_utils(count, n, x);
	else
		ft_putchar('0');
	return (count);
}

int	print_pointer(void	*ptr)
{	
	int	count;

	count = ft_putstr("0x");
	count += hex((unsigned long long)ptr, 'p');
	return (count);
}

int	ft_formats(va_list args, const char s)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (s == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		len += ft_putnbr_u(va_arg(args, unsigned int));
	else if (s == 'p')
		len += print_pointer(va_arg(args, void *));
	else if (s == 'X' || s == 'x')
		len += hex((unsigned long long)va_arg(args, unsigned int), s);
	else if (s == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 's' || str[i + 1] == 'c'
				|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
				|| str[i + 1] == 'p' || str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == '%'))
			length += ft_formats(args, (str[++i]));
		else if (str[i] != '%')
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
