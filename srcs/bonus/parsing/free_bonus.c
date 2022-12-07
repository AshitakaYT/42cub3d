/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:18:22 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 16:46:57 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

void	ft_strfree(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

void	cube_freemap(t_cube *c)
{
	if (c->map)
		ft_freetab(c->map);
	if (c->ma)
	{
		if (c->ma->tab)
			ft_freetab(c->ma->tab);
		if (c->ma->p)
		{
			free(c->ma->p);
			c->ma->p = NULL;
		}
		free(c->ma);
		c->ma = NULL;
	}
}

void	cube_freeelpath(t_cube *c)
{
	if (c->el->elems)
		ft_freetab(c->el->elems);
	if (c->el->so)
		ft_strfree(c->el->so);
	if (c->el->no)
		ft_strfree(c->el->no);
	if (c->el->ea)
		ft_strfree(c->el->ea);
	if (c->el->we)
		ft_strfree(c->el->we);
	if (c->el->po)
		ft_strfree(c->el->po);
}

void	cube_freeelcolors(t_cube *c)
{
	if (c->el->fl)
	{
		if (c->el->fl->code)
		{
			free(c->el->fl->code);
			c->el->fl->code = NULL;
		}
		free(c->el->fl);
		c->el->fl = NULL;
	}
	if (c->el->ce)
	{	
		if (c->el->ce->code)
		{
			free(c->el->ce->code);
			c->el->ce->code = NULL;
		}
		free(c->el->ce);
		c->el->ce = NULL;
	}
}

int	cube_free(t_cube *c)
{
	cube_freemap(c);
	if (c->el != NULL)
	{
		cube_freeelpath(c);
		cube_freeelcolors(c);
		free(c->el);
		c->el = NULL;
	}
	return (0);
}
