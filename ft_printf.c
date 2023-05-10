/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:53 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/10 12:58:40 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	write_str(va_list args)
{
	char	*s;
	int		count;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
		count += write(1, "(null)", 6);
	else
	{
		while (*s != '\0')
		{
			count += write(1, s, 1);
			s++;
		}
	}
	return (count);
}

void	write_nbr(long nbr, int *count, char format)
{
	long	temp;

	if (format == 'u' && nbr < 0)
		nbr += 4294967295 + 1;
	if (nbr == -2147483648)
		*count += write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		*count += write(1, "-", 1);
		write_nbr(nbr * -1, count, format);
	}
	else if (nbr < 10)
	{
		temp = nbr + 48;
		*count += write(1, &temp, 1);
	}
	else
	{
		write_nbr(nbr / 10, count, format);
		write_nbr(nbr % 10, count, format);
	}
}

void	check_format(const char *format, int i, va_list args, int *count)
{
	int	c;

	if (format[i] == '%')
		*count += write(1, "%", 1);
	else if (format[i] == 'c')
	{
		c = va_arg(args, int);
		*count += write(1, &c, 1);
	}
	else if (format[i] == 's')
		*count += write_str(args);
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		write_nbr(va_arg(args, int), count, format[i]);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = i + 1;
			check_format(format, i, args, &count);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
