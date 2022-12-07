/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:35:40 by aucousin          #+#    #+#             */
/*   Updated: 2022/11/29 10:15:55 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	draw_wall(t_cube *c, int beginY, int endY, int color)
{
	while (beginY < endY)
	{
		my_mlx_pixel_put(c->img, c->r, beginY, color);
		beginY++;
	}
	return (0);
}

float	cube_deg_to_rad(float a)
{
	return (a * M_PI / 180.0);
}

float	cube_distance2(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	cube_updatepi(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	else if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	cube_compare_distance(t_cube *c)
{
	if (c->ma->p->dist_h < c->ma->p->dist_v)
	{
		c->ma->p->rx = c->ma->p->hx;
		c->ma->p->ry = c->ma->p->hy;
		c->ma->p->dist_f = c->ma->p->dist_h;
	}
	else
	{
		c->ma->p->rx = c->ma->p->vx;
		c->ma->p->ry = c->ma->p->vy;
		c->ma->p->dist_f = c->ma->p->dist_v;
	}
	c->ma->p->mx = (int)c->ma->p->rx / SIZE;
	c->ma->p->my = (int)c->ma->p->ry / SIZE;
	if (c->ma->tab[c->ma->p->my][c->ma->p->mx] == 'P')
		c->type = 1;
	else
		c->type = 2;
}
