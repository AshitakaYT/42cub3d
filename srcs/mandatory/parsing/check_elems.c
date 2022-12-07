/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:08:00 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 17:57:51 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	ft_strbeginbywhite(char *str, char *begin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (ft_strlen(&str[i]) < ft_strlen(begin))
		return (-1);
	while (begin[j])
	{
		if (begin[j] != str[i])
			return (-1);
		i++;
		j++;
	}
	return (0);
}

char	*cube_check_elem(char **map, char *elem)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strbeginbywhite(map[i], elem) == 0
			&& ft_count_words(map[i], " \t\r\v\f") == 2)
			return (map[i]);
		i++;
	}
	ft_printreturn("Error. check_elem: didn't found elem.\n", 2, -1);
	return (NULL);
}

int	cube_atoi(char const *str, int *i)
{
	int			result;
	int			j;

	result = 0;
	j = 0;
	if (!str[(*i)] || !ft_isdigit(str[(*i)]))
		return (-1);
	while (str[(*i)] && str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		result = result * 10 + str[(*i)] - '0';
		if (result > 255)
			return (-1);
		(*i)++;
		j++;
	}
	if ((str[(*i)] && str[(*i)] != ',' && str[(*i)] != ' ') || j > 3)
		return (-1);
	return (result);
}

int	cube_checkcolor(char *str)
{
	int	i;
	int	r;
	int	b;
	int	g;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	r = cube_atoi(str, &i);
	i++;
	g = cube_atoi(str, &i);
	i++;
	b = cube_atoi(str, &i);
	while (str[i])
	{
		if (str[i] != ' ')
			return (-1);
		i++;
	}
	if (r == -1 || b == -1 || g == -1)
		return (-1);
	return (0);
}

int	cube_checkelems(t_cube *c)
{
	if (cube_check_elem(c->el->elems, "NO ")
		&& cube_check_elem(c->el->elems, "SO ")
		&& cube_check_elem(c->el->elems, "EA ")
		&& cube_check_elem(c->el->elems, "WE ")
		&& cube_checkcolor(cube_check_elem(c->el->elems, "F ")) != -1
		&& cube_checkcolor(cube_check_elem(c->el->elems, "C ")) != -1)
		return (0);
	return (-1);
}
