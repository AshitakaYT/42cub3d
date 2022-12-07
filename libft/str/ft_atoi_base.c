/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:16:46 by aucousin          #+#    #+#             */
/*   Updated: 2022/11/06 16:28:29 by aucousin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_position_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_strcheck_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (!ft_is_once_in_base(base, base[i])
			|| base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || base[i] == '\f'
			|| base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long int	result;
	int			len;

	len = ft_strlen(base);
	sign = 1;
	result = 0;
	if (!ft_strcheck_base(base))
		return (0);
	while (*str == '\f' || *str == '\n' || *str == '\r' \
			|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_is_once_in_base(base, *str))
	{
		result = result * len + ft_position_base(base, *str);
		str++;
	}
	return (result * sign);
}
