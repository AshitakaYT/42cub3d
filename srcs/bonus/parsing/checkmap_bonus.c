/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:21:00 by aucousin          #+#    #+#             */
/*   Updated: 2022/11/29 13:18:59 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	cube_checkmap_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_isincharset(map[i][j], "01WSNE P"))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	cube_checkmap_player(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_isincharset(map[i][j], "NSEW"))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	cube_getmap(t_cube *c)
{
	if (cube_initmap(c) == -1)
		return (ft_printreturn("Error : init failed.\n", 2, -1));
	if (cube_checkmap_characters(c->ma->tab) == -1)
		return (ft_printreturn("Error : characters failed.\n", 2, -1));
	if (cube_checkmap_player(c->ma->tab) == -1)
		return (ft_printreturn("Error : player failed.\n", 2, -1));
	if (cube_checkclosedspaces(c->ma->tab) == -1)
		return (ft_printreturn("Error : checkclosedspaces failed.\n", 2, -1));
	if (cube_checkmap_closedfrombot(c->ma->tab, c->ma->hei, c->ma->wid) == -1)
		return (ft_printreturn("Error. getmap: closedfrombot failed.\n", 2, -1));
	if (cube_checkmap_closedfromtop(c->ma->tab, c->ma->wid) == -1)
		return (ft_printreturn("Error. getmap: closedfromtop failed.\n", 2, -1));
	if (cube_checkmap_closedfromleft(c->ma->tab) == -1)
		return (ft_printreturn("Error : closedfromleft failed.\n", 2, -1));
	if (cube_checkmap_closedfromright(c->ma->tab, c->ma->wid) == -1)
		return (ft_printreturn("Error :closedfromright failed.\n", 2, -1));
	return (0);
}
