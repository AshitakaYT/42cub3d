/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:56:07 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 17:14:39 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	cube_getmapwid(char **map)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j > w)
				w = j;
			j++;
		}
		i++;
	}
	return (w);
}

char	**cube_fillmapwithspaces(char **tab, int w, int h)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * (h + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		j = 0;
		new[i] = ft_calloc((w + 2), sizeof(char));
		if (!new[i])
			return (NULL);
		while (tab[i][j])
		{
			new[i][j] = tab[i][j];
			j++;
		}
		while (j <= w)
			new[i][j++] = ' ';
		i++;
	}
	new[i] = 0;
	return (new);
}

int	cube_initmap(t_cube *c)
{
	c->ma = malloc(sizeof(t_map));
	if (!c->ma)
		return (-1);
	c->ma->p = NULL;
	c->ma->hei = ft_tablen(c->map);
	c->ma->wid = cube_getmapwid(c->map);
	c->ma->tab = cube_fillmapwithspaces(c->map, c->ma->wid, c->ma->hei);
	ft_puttab(c->ma->tab);
	return (0);
}
