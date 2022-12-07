/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:20:57 by aucousin          #+#    #+#             */
/*   Updated: 2022/09/29 18:38:46 by aucousin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_is_once_in_base(char *base, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i])
	{
		if (base[i] == c && count == 1)
			return (0);
		else if (base[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (!ft_is_once_in_base(base, base[i]) \
			|| base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (1);
}
