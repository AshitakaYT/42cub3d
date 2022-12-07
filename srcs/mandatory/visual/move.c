/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:47:30 by aucousin          #+#    #+#             */
/*   Updated: 2022/11/22 17:04:03 by aucousin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

void	cube_move_forward(t_cube *c)
{
	float	dx;
	float	dy;

	dx = c->ma->p->dx * 5;
	dy = c->ma->p->dy * 5;
	if ((int)(c->ma->p->x + c->ma->p->dx) / SIZE >= 0
		&& (int)(c->ma->p->x + c->ma->p->dx) / SIZE < c->ma->wid
		&& (int)(c->ma->p->y) / SIZE >= 0
		&& (int)(c->ma->p->y) / SIZE < c->ma->hei
		&& !ft_isincharset(c->ma->tab
		[(int)(c->ma->p->y) / SIZE]
		[(int)(c->ma->p->x + dx) / SIZE], "1P"))
		c->ma->p->x += c->ma->p->dx;
	if ((int)(c->ma->p->x) / SIZE >= 0
		&& (int)(c->ma->p->x) / SIZE < c->ma->wid
		&& (int)(c->ma->p->y + c->ma->p->dy) / SIZE >= 0
		&& (int)(c->ma->p->y + c->ma->p->dy) / SIZE < c->ma->hei
		&& !ft_isincharset(c->ma->tab
		[(int)(c->ma->p->y + dy) / SIZE]
		[(int)(c->ma->p->x) / SIZE], "1P"))
		c->ma->p->y += c->ma->p->dy;
}

void	cube_move_backward(t_cube *c)
{
	float	dx;
	float	dy;

	dx = c->ma->p->dx * 5;
	dy = c->ma->p->dy * 5;
	if ((int)(c->ma->p->x - c->ma->p->dx) / SIZE >= 0
		&& (int)(c->ma->p->x - c->ma->p->dx) / SIZE < c->ma->wid
		&& (int)(c->ma->p->y) / SIZE >= 0
		&& (int)(c->ma->p->y) / SIZE < c->ma->hei
		&& !ft_isincharset(c->ma->tab
		[(int)(c->ma->p->y) / SIZE]
		[(int)(c->ma->p->x - dx) / SIZE], "1P"))
		c->ma->p->x -= c->ma->p->dx;
	if ((int)(c->ma->p->x) / SIZE >= 0
		&& (int)(c->ma->p->x) / SIZE < c->ma->wid
		&& (int)(c->ma->p->y - c->ma->p->dy) / SIZE >= 0
		&& (int)(c->ma->p->y - c->ma->p->dy) / SIZE < c->ma->hei
		&& !ft_isincharset(c->ma->tab
		[(int)(c->ma->p->y - dy) / SIZE]
		[(int)(c->ma->p->x) / SIZE], "1P"))
		c->ma->p->y -= c->ma->p->dy;
}

void	cube_turn_right(t_cube *c)
{
	c->ma->p->a += 0.05;
	if (c->ma->p->a > (2 * PI))
		c->ma->p->a -= (2 * PI);
	c->ma->p->dx = cos(c->ma->p->a);
	c->ma->p->dy = sin(c->ma->p->a);
}

void	cube_turn_left(t_cube *c)
{
	c->ma->p->a -= 0.05;
	if (c->ma->p->a < 0)
		c->ma->p->a += (2 * PI);
	c->ma->p->dx = cos(c->ma->p->a);
	c->ma->p->dy = sin(c->ma->p->a);
}
