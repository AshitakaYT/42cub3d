/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3d_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:46:11 by rgeral            #+#    #+#             */
/*   Updated: 2022/12/04 12:28:52 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

void	cube_door(t_cube *c)
{
	if (c->ma->p->dist_h < c->ma->p->dist_v
		&& c->ma->p->ra > 0 && c->ma->p->ra < PI)
		cube_draw_wall_s(c, c->ma->po,
			(c->line_o / 2),
			c->line_h + (c->line_o / 2));
	else if (c->ma->p->dist_h < c->ma->p->dist_v && c->ma->p->ra > PI)
		cube_draw_wall_n(c, c->ma->po,
			(c->line_o / 2),
			c->line_h + (c->line_o / 2));
	else if (c->ma->p->dist_h > c->ma->p->dist_v
		&& c->ma->p->ra > PI / 2 && c->ma->p->ra < 3 * PI / 2)
		cube_draw_wall_w(c, c->ma->po,
			(c->line_o / 2),
			c->line_h + (c->line_o / 2));
	else if (c->ma->p->dist_h > c->ma->p->dist_v
		&& (c->ma->p->ra < PI / 2 || c->ma->p->ra > 3 * PI / 2))
		cube_draw_wall_e(c, c->ma->po,
			(c->line_o / 2),
			c->line_h + (c->line_o / 2));
}

void	cube_render(t_cube *c)
{
	if (c->type == 1)
		cube_door(c);
	else if (c->ma->p->dist_h < c->ma->p->dist_v
		&& c->ma->p->ra > 0 && c->ma->p->ra < PI)
		cube_draw_wall_s(c, c->ma->so,
			(c->line_o / 2), c->line_h + (c->line_o / 2));
	else if (c->ma->p->dist_h < c->ma->p->dist_v && c->ma->p->ra > PI)
		cube_draw_wall_n(c, c->ma->no,
			(c->line_o / 2), c->line_h + (c->line_o / 2));
	else if (c->ma->p->dist_h > c->ma->p->dist_v
		&& c->ma->p->ra > PI / 2 && c->ma->p->ra < 3 * PI / 2)
		cube_draw_wall_w(c, c->ma->we,
			(c->line_o / 2),
			c->line_h + (c->line_o / 2));
	else if (c->ma->p->dist_h > c->ma->p->dist_v
		&& (c->ma->p->ra < PI / 2 || c->ma->p->ra > 3 * PI / 2))
		cube_draw_wall_e(c, c->ma->ea,
			(c->line_o / 2),
			c->line_h + (c->line_o / 2));
	cube_draw_wall_cf(c);
}

void	cube_3d(t_cube *c, int r)
{
	c->r = r;
	c->ca = c->ma->p->a - c->ma->p->ra;
	c->ca = cube_updatepi(c->ca);
	c->ma->p->dist_f = cos(c->ca) * c->ma->p->dist_f;
	c->line_h = 1080 * 12 / (c->ma->p->dist_f);
	c->line_hlim = c->line_h;
	c->ty_offset = 0;
	if (c->line_h > 1080)
	{
		c->ty_offset = (c->line_hlim - 1080) / 4;
		c->line_h = 1080;
	}
	c->line_o = 540 - (c->line_h * 0.5);
	cube_render(c);
}

void	cube_display_rays(t_cube *c)
{
	int		r;

	r = 0;
	c->ma->p->ra = cube_updatepi(c->ma->p->a - DR * 30);
	while (r < 1440)
	{
		cube_init_rays(c);
		cube_horizontal_rays(c);
		cube_vertical_rays(c);
		cube_compare_distance(c);
		cube_3d(c, r);
		c->ma->p->ra = cube_updatepi(c->ma->p->ra + (DR / 24));
		r++;
	}
}
