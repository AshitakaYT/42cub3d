/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:10:25 by aucousin          #+#    #+#             */
/*   Updated: 2022/09/28 18:28:49 by aucousin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		i;

	if (!s || !f)
		return (NULL);
	map = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (s[i])
	{
		map[i] = (f)(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
