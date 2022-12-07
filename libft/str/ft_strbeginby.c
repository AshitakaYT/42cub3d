/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbeginby.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:12:57 by aucousin          #+#    #+#             */
/*   Updated: 2022/10/17 15:13:33 by aucousin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_strbeginby(char *str, char *begin)
{
	int	i;

	i = 0;
	if (ft_strlen(str) < ft_strlen(begin))
		return (-1);
	while (begin[i])
	{
		if (begin[i] != str[i])
			return (-1);
		i++;
	}
	return (0);
}
