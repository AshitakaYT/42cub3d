/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls3d_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:28:34 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/04 14:34:02 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

void	cube_draw_wall_cf(t_cube *c)
{
	draw_wall(c,
		0,
		(c->line_o / 2),
		c->el->ce->co);
	draw_wall(c,
		c->line_h + (c->line_o / 2),
		1080,
		c->el->fl->co);
}

void	cube_draw_wall_n(t_cube *c, t_image t, int beginY, int endY)
{
	int		pos;
	float	y;
	float	x;
	float	ty_step;

	ty_step = t.size.y / 4 / c->line_hlim;
	y = c->ty_offset * ty_step;
	x = c->ma->p->rx;
	while (x >= SIZE)
		x -= SIZE;
	x = (x / SIZE) * t.size.x / 4;
	while (beginY < endY)
	{
		pos = ((int)y * t.line_size) + ((int)x * (t.bits_per_pixel / 8));
		my_mlx_pixel_put(c->img, c->r, beginY,
			t.intaddr[pos]);
		beginY++;
		if (y + ty_step < t.size.y / 4)
			y += ty_step;
	}
}

void	cube_draw_wall_s(t_cube *c, t_image t, int beginY, int endY)
{
	int		pos;
	float	y;
	float	x;
	float	ty_step;

	ty_step = t.size.y / 4 / c->line_hlim;
	y = c->ty_offset * ty_step;
	x = c->ma->p->rx;
	while (x >= SIZE)
		x -= SIZE;
	x = SIZE - x;
	x = (x / SIZE) * t.size.x / 4;
	while (beginY < endY)
	{
		pos = ((int)y * t.line_size) + ((int)x * (t.bits_per_pixel / 8));
		my_mlx_pixel_put(c->img, c->r, beginY,
			t.intaddr[pos]);
		beginY++;
		if (y + ty_step < t.size.y / 4)
			y += ty_step;
	}
}

void	cube_draw_wall_w(t_cube *c, t_image t, int beginY, int endY)
{
	int		pos;
	float	y;
	float	x;
	float	ty_step;

	ty_step = t.size.y / 4 / c->line_hlim;
	y = c->ty_offset * ty_step;
	x = c->ma->p->ry;
	while (x >= SIZE)
		x -= SIZE;
	x = SIZE - x;
	x = x / SIZE * t.size.x / 4;
	while (beginY < endY)
	{
		pos = ((int)y * t.line_size) + ((int)x * (t.bits_per_pixel / 8));
		my_mlx_pixel_put(c->img, c->r, beginY,
			t.intaddr[pos]);
		beginY++;
		if (y + ty_step < t.size.y / 4)
			y += ty_step;
	}
}

void	cube_draw_wall_e(t_cube *c, t_image t, int beginY, int endY)
{
	int		pos;
	float	y;
	float	x;
	float	ty_step;

	ty_step = t.size.y / 4 / c->line_hlim;
	y = c->ty_offset * ty_step;
	x = c->ma->p->ry;
	while (x >= SIZE)
		x -= SIZE;
	x = x / SIZE * t.size.x / 4;
	while (beginY < endY)
	{
		pos = ((int)y * t.line_size) + ((int)x * (t.bits_per_pixel / 8));
		my_mlx_pixel_put(c->img, c->r, beginY,
			t.intaddr[pos]);
		beginY++;
		if (y + ty_step < t.size.y / 4)
			y += ty_step;
	}
}
