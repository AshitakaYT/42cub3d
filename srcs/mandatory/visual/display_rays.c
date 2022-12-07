/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:31:38 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 17:22:29 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

void	cube_init_rays(t_cube *c)
{
	c->ma->p->dist_h = 1000000;
	c->ma->p->dist_v = 1000000;
	c->ma->p->yo = 0;
	c->ma->p->xo = 0;
	c->type = 0;
}

void	cube_init_horizontal_rays(t_cube *c)
{
	c->ma->p->dof = 0;
	c->ma->p->atan = -1 / tan(c->ma->p->ra);
	if (c->ma->p->ra > PI)
	{
		c->ma->p->ry = ((((int)c->ma->p->y) / SIZE) * SIZE) - 0.0001;
		c->ma->p->rx = (c->ma->p->y - c->ma->p->ry)
			* c->ma->p->atan + c->ma->p->x;
		c->ma->p->yo = -SIZE;
		c->ma->p->xo = -c->ma->p->yo * c->ma->p->atan;
	}
	else if (c->ma->p->ra < PI)
	{
		c->ma->p->ry = ((((int)c->ma->p->y) / SIZE) * SIZE) + SIZE;
		c->ma->p->rx = (c->ma->p->y - c->ma->p->ry)
			* c->ma->p->atan + c->ma->p->x;
		c->ma->p->yo = SIZE;
		c->ma->p->xo = -c->ma->p->yo * c->ma->p->atan;
	}
	else
	{
		c->ma->p->rx = c->ma->p->x;
		c->ma->p->ry = c->ma->p->y;
		c->ma->p->dof = c->ma->hei;
	}
}

void	cube_init_vertical_rays(t_cube *c)
{
	c->ma->p->dof = 0;
	c->ma->p->ntan = -tan(c->ma->p->ra);
	if (c->ma->p->ra > (PI / 2) && c->ma->p->ra < (3 * PI) / 2)
	{
		c->ma->p->rx = ((((int)c->ma->p->x) / SIZE) * SIZE) - 0.0001;
		c->ma->p->ry = (c->ma->p->x - c->ma->p->rx)
			* c->ma->p->ntan + c->ma->p->y;
		c->ma->p->xo = -SIZE;
		c->ma->p->yo = -c->ma->p->xo * c->ma->p->ntan;
	}
	else if (c->ma->p->ra < (PI / 2) || c->ma->p->ra > (3 * PI) / 2)
	{
		c->ma->p->rx = ((((int)c->ma->p->x) / SIZE) * SIZE) + SIZE;
		c->ma->p->ry = (c->ma->p->x - c->ma->p->rx)
			* c->ma->p->ntan + c->ma->p->y;
		c->ma->p->xo = SIZE;
		c->ma->p->yo = -c->ma->p->xo * c->ma->p->ntan;
	}
	else
	{
		c->ma->p->rx = c->ma->p->x;
		c->ma->p->ry = c->ma->p->y;
		c->ma->p->dof = c->ma->wid;
	}
}

void	cube_vertical_rays(t_cube *c)
{
	cube_init_vertical_rays(c);
	while (c->ma->p->dof < c->ma->wid)
	{
		c->ma->p->mx = (int)c->ma->p->rx / SIZE;
		c->ma->p->my = (int)c->ma->p->ry / SIZE;
		if (c->ma->p->dof > 100
			|| (c->ma->p->mx <= c->ma->wid && c->ma->p->my < c->ma->hei
				&& c->ma->p->mx >= 0 && c->ma->p->my >= 0
				&& (c->ma->tab[c->ma->p->my][c->ma->p->mx] == '1')))
		{
			c->ma->p->dof = c->ma->wid;
			c->ma->p->vx = c->ma->p->rx;
			c->ma->p->vy = c->ma->p->ry;
			c->ma->p->dist_v = cube_distance2(c->ma->p->x,
					c->ma->p->y, c->ma->p->rx, c->ma->p->ry);
		}
		else
		{
			c->ma->p->rx += c->ma->p->xo;
			c->ma->p->ry += c->ma->p->yo;
			c->ma->p->dof += 1;
		}
	}
}

void	cube_horizontal_rays(t_cube *c)
{
	cube_init_horizontal_rays(c);
	while (c->ma->p->dof < c->ma->hei)
	{
		c->ma->p->mx = (int)c->ma->p->rx / SIZE;
		c->ma->p->my = (int)c->ma->p->ry / SIZE;
		if (c->ma->p->dof > 100
			|| (c->ma->p->mx <= c->ma->wid && c->ma->p->my < c->ma->hei
				&& c->ma->p->mx >= 0 && c->ma->p->my >= 0
				&& (c->ma->tab[c->ma->p->my][c->ma->p->mx] == '1')))
		{
			c->ma->p->dof = c->ma->hei;
			c->ma->p->hx = c->ma->p->rx;
			c->ma->p->hy = c->ma->p->ry;
			c->ma->p->dist_h = cube_distance2(c->ma->p->x,
					c->ma->p->y, c->ma->p->rx, c->ma->p->ry);
		}
		else
		{
			c->ma->p->rx += c->ma->p->xo;
			c->ma->p->ry += c->ma->p->yo;
			c->ma->p->dof += 1;
		}
	}
}
