/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:39:54 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:54:16 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_putchar_dprintf(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_dprintf(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_call_right_function_dprintf(char c, va_list ap, int fd)
{
	long long	p;

	if (c == 'c')
		return (ft_putchar_dprintf(fd, va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_dprintf(fd, va_arg(ap, char *)));
	else if (c == 'p')
	{
		p = va_arg(ap, long long);
		return (ft_putptr_dprintf(p, fd));
	}
	else if (c == 'd' || c == 'i')
		return (ft_pnb_dprintf(va_arg(ap, int), "0123456789", 0, fd));
	else if (c == 'u')
		return (ft_pnbu_dprintf(va_arg(ap, unsigned int), "0123456789", 0, fd));
	else if (c == 'x')
		return (ft_pnbu_dprintf(va_arg(ap, unsigned int),
				"0123456789abcdef", 0, fd));
	else if (c == 'X')
		return (ft_pnbu_dprintf(va_arg(ap, unsigned int),
				"0123456789ABCDEF", 0, fd));
	else if (c == '%')
		return (ft_putchar_dprintf(fd, c));
	return (0);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	ap;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			bytes += ft_putchar_dprintf(fd, str[i]);
			i++;
		}
		else if (str[i + 1] && ft_is_variable(str[i + 1]))
		{
			bytes += ft_call_right_function_dprintf(str[i + 1], ap, fd);
			i += 2;
		}
	}
	return (bytes);
}
