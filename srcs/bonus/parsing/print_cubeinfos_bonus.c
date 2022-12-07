/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cubeinfos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:41:24 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/03 09:30:42 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

void	cube_printelem(t_elem	*el)
{
	ft_printf("============= ELEMENTS ==============\n");
	if (el->elems)
	{
		ft_puttab(el->elems);
		ft_printf("-----------\n");
	}
	if (el->so)
		ft_printf("so = %s\n", el->so);
	if (el->no)
		ft_printf("no = %s\n", el->no);
	if (el->we)
		ft_printf("we = %s\n", el->we);
	if (el->ea)
		ft_printf("ea = %s\n", el->ea);
	if (el->fl)
		ft_printf("fl = r %d g %d b %d\n", el->fl->r, el->fl->g, el->fl->b);
	if (el->ce)
		ft_printf("ce = r %d g %d b %d\n", el->ce->r, el->ce->g, el->ce->b);
}

void	cube_printmap(t_map	*map)
{
	ft_printf("============= MAP ==============\n");
	if (map->tab)
		ft_puttab(map->tab);
	ft_printf("height = %d\n", map->hei);
	ft_printf("width = %d\n", map->wid);
}

void	cube_print(t_cube c)
{
	ft_printf("============= CUBE ==============\n");
	if (c.map)
		ft_puttab(c.map);
	if (c.ma != NULL)
		cube_printmap(c.ma);
	if (c.el != NULL)
		cube_printelem(c.el);
}
