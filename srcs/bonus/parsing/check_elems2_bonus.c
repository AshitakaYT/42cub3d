/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elems2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:06:58 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/04 12:05:35 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	test_openclose(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int	cube_checkpaths(t_cube *c)
{
	int	i;

	i = 0;
	if (ft_strendby(c->el->no, ".xpm") == -1
		|| ft_strendby(c->el->ea, ".xpm") == -1
		|| ft_strendby(c->el->we, ".xpm") == -1
		|| ft_strendby(c->el->so, ".xpm") == -1
		|| ft_strendby(c->el->po, ".xpm") == -1)
		return (ft_printreturn("Textures must be xpm.\n", 2, -1));
	if (test_openclose(c->el->no) == -1
		|| test_openclose(c->el->ea) == -1
		|| test_openclose(c->el->we) == -1
		|| test_openclose(c->el->so) == -1
		|| test_openclose(c->el->po) == -1)
		return (ft_printreturn("Error. Open failed.\n", 2, -1));
	return (0);
}

int	cube_getelems(t_cube *c)
{
	if (cube_checkelems(c) == -1)
		return (ft_printreturn("Error. Checkelems failed.\n", 2, -1));
	cube_createcolors(c);
	c->el->no = cube_get_path(cube_check_elem(c->el->elems, "NO "));
	c->el->ea = cube_get_path(cube_check_elem(c->el->elems, "EA "));
	c->el->we = cube_get_path(cube_check_elem(c->el->elems, "WE "));
	c->el->so = cube_get_path(cube_check_elem(c->el->elems, "SO "));
	c->el->po = cube_get_path(cube_check_elem(c->el->elems, "PO "));
	cube_getcolor(c->el->fl, cube_check_elem(c->el->elems, "F "));
	cube_getcolor(c->el->ce, cube_check_elem(c->el->elems, "C "));
	cube_get_color_code(c->el->fl);
	cube_get_color_code(c->el->ce);
	if (!c->el->no || ! c->el->ea || !c->el->so || !c->el->we
		|| !c->el->po || cube_checkpaths(c) == -1)
		return (ft_printreturn("Error. getelems: textures failed.\n", 2, -1));
	return (0);
}
