/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:18:13 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:55:55 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_get_len(int nb, char *base_to)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb = nb / ft_strlen(base_to);
		i++;
	}
	return (i);
}

char	*ft_str_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nb;
	int			len;
	char		*newnbr;
	int			j;

	j = 0;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	len = ft_get_len(ft_atoi_base(nbr, base_from), base_to);
	newnbr = malloc((len + 1) * sizeof(char));
	if (nb < 0)
	{
		nb *= -1;
		j = 1;
	}
	while (len--)
	{
		newnbr[len] = base_to[nb % ft_strlen(base_to)];
		nb = nb / ft_strlen(base_to);
	}
	if (j == 1)
		newnbr[0] = '-';
	newnbr[ft_get_len(ft_atoi_base(nbr, base_from), base_to)] = '\0';
	return (newnbr);
}
