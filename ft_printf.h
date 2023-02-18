/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:09 by armartir          #+#    #+#             */
/*   Updated: 2023/01/25 14:51:49 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int				ft_putchar(int c);
int				ft_putstr(const char *s);
int				ft_putnbr(int num);
unsigned int	ft_putnbr_u(unsigned int n);
int				hex_utils(int c, unsigned long long tmp, char x);
int				hex(unsigned long long n, char x);
int				print_pointer(void	*ptr);
int				ft_formats(va_list args, const char s);
int				ft_printf(const char *str, ...);

#endif