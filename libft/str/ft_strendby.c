/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendby.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:01:11 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:55:00 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_strendby(char *str, char *end)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = ft_strlen(end);
	if (i < j)
		return (-1);
	while (j && str[i--] == end[j--])
	{
	}
	if (j)
		return (-1);
	return (0);
}
