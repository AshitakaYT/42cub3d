/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:06:26 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 17:02:39 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	cube_getcolor(t_color *c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	c->r = cube_atoi(str, &i);
	i++;
	c->g = cube_atoi(str, &i);
	i++;
	c->b = cube_atoi(str, &i);
	return (0);
}

int	cube_createcolors(t_cube *c)
{
	c->el->fl = malloc(sizeof(t_color));
	if (!c->el->fl)
		return (ft_printreturn("Error. createcolors: malloc failed.\n", 2, -1));
	c->el->ce = malloc(sizeof(t_color));
	if (!c->el->ce)
		return (ft_printreturn("Error. createcolors: malloc failed.\n", 2, -1));
	c->el->fl->a = -1;
	c->el->fl->r = -1;
	c->el->fl->g = -1;
	c->el->fl->b = -1;
	c->el->ce->a = -1;
	c->el->ce->r = -1;
	c->el->ce->g = -1;
	c->el->ce->b = -1;
	return (0);
}

void	cube_get_code(t_color *c, int color)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_itoa(color);
	tmp3 = ft_str_convert_base(tmp, "0123456789", "0123456789ABCDEF");
	if (ft_strlen(tmp3) == 1)
		tmp2 = ft_strjoin("0", tmp3);
	else
		tmp2 = ft_strdup(tmp3);
	ft_strfree(tmp);
	tmp = c->code;
	c->code = ft_strjoin(tmp, tmp2);
	ft_strfree(tmp);
	ft_strfree(tmp2);
	ft_strfree(tmp3);
}

int	cube_get_color_code(t_color *c)
{
	c->code = malloc(sizeof(char));
	if (!c->code)
		return (-1);
	c->code[0] = '\0';
	cube_get_code(c, c->r);
	cube_get_code(c, c->g);
	cube_get_code(c, c->b);
	c->co = ft_atoi_base(c->code, "0123456789ABCDEF");
	return (0);
}

char	*cube_get_path(char *str)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	i += 2;
	while (str[i] && str[i] == ' ')
		i++;
	j = 0;
	while (str[i + j] && str [i + j] != ' ')
		j++;
	path = ft_substr(str, i, j);
	return (path);
}
