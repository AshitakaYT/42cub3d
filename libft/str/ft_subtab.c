/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:36:24 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:54:28 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

char	**ft_subtab(char **tab, unsigned int start, size_t len)
{
	char	**ret;
	size_t	j;

	if (!tab)
		return (NULL);
	j = 0;
	if (start >= (unsigned int)ft_tablen(tab))
		ret = malloc(sizeof(char *));
	else if (len > ft_tablen(tab) - start)
		ret = malloc(sizeof(char *) * (ft_tablen(tab) - start + 1));
	else
		ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	while (start + j < (unsigned int)ft_tablen(tab) && j < len)
	{
		ret[j] = ft_strdup(tab[start + j]);
		if (!ret[j])
			return (ft_freetab(ret));
		j++;
	}
	ret[j] = 0;
	return (ret);
}
