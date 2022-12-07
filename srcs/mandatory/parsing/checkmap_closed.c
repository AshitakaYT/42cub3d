/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:57:27 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 17:31:00 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	cube_checkmap_closedfromleft(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] && map[i][j] != '1' && map[i][j] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	cube_checkmap_closedfromright(char **map, int w)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = w;
		while (j > 0 && map[i][j] == ' ')
			j--;
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	cube_checkmap_closedfromtop(char **map, int w)
{
	int	i;
	int	j;

	j = 0;
	while (j < w)
	{
		i = 0;
		while (map[i] && map[i][j] == ' ')
			i++;
		if (map[i] && map[i][j] != '1' && map[i][j] != ' ')
			return (-1);
		j++;
	}
	return (0);
}

int	cube_checkmap_closedfrombot(char **map, int h, int w)
{
	int	i;
	int	j;

	j = 0;
	while (j < w)
	{
		i = h - 1;
		while (i > 0 && map[i][j] == ' ')
			i--;
		if (i >= 0 && map[i][j] != '1' && map[i][j] != ' ')
			return (-1);
		j++;
	}
	return (0);
}

int	cube_checkclosedspaces(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
			{
				if ((map[i][j + 1] && map[i][j + 1] != '1'
				&& map[i][j + 1] != ' ')
				|| (j != 0 && map[i][j - 1] != '1' && map[i][j - 1] != ' ')
				|| (map[i + 1] && map[i + 1][j] != '1' && map[i + 1][j] != ' ')
				|| (i != 0 && map[i - 1][j] != '1' && map[i - 1][j] != ' '))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
