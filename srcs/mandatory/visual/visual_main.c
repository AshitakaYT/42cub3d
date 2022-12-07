/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:46:48 by rgeral            #+#    #+#             */
/*   Updated: 2022/12/06 08:13:05 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (int64_t)1000) + (tv.tv_usec / 1000));
}

void	cube_open_close_door(t_cube *c)
{
	if ((int)(c->ma->p->x + (c->ma->p->dx * 10)) / SIZE >= 0
		&& (int)(c->ma->p->y + (c->ma->p->dy * 10)) / SIZE >= 0
		&& (int)(c->ma->p->x + c->ma->p->dx * 10) / SIZE < c->ma->wid
		&& (int)(c->ma->p->y + c->ma->p->dy * 10) / SIZE < c->ma->hei
		&& ft_isincharset(c->ma->tab
		[(int)(c->ma->p->y + (c->ma->p->dy * 10)) / SIZE]
		[(int)(c->ma->p->x + (c->ma->p->dx * 10)) / SIZE], "P"))
		c->ma->tab
		[(int)(c->ma->p->y + (c->ma->p->dy * 10)) / SIZE]
		[(int)(c->ma->p->x + (c->ma->p->dx * 10)) / SIZE] = '2';
	else if ((int)(c->ma->p->x + (c->ma->p->dx * 10)) / SIZE >= 0
		&& (int)(c->ma->p->y + (c->ma->p->dy * 10)) / SIZE >= 0
		&& (int)(c->ma->p->x + c->ma->p->dx * 10) / SIZE < c->ma->wid
		&& (int)(c->ma->p->y + c->ma->p->dy * 10) / SIZE < c->ma->hei
		&& ft_isincharset(c->ma->tab
		[(int)(c->ma->p->y + (c->ma->p->dy * 10)) / SIZE]
		[(int)(c->ma->p->x + (c->ma->p->dx * 10)) / SIZE], "2"))
		c->ma->tab
		[(int)(c->ma->p->y + (c->ma->p->dy * 10)) / SIZE]
		[(int)(c->ma->p->x + (c->ma->p->dx * 10)) / SIZE] = 'P';
}

int	loop_hook(t_cube *c)
{
	if (c->key_forward)
		cube_move_forward(c);
	if (c->key_backward)
		cube_move_backward(c);
	if (c->key_strafe_right)
		straf_right(c);
	if (c->key_strafe_left)
		straf_left(c);
	if (c->key_rotate_left)
		cube_turn_left(c);
	if (c->key_rotate_right)
		cube_turn_right(c);
	if (c->key_open)
		cube_open_close_door(c);
	cube_minimap(c);
	return (0);
}

int	cube_mlx(t_cube *c)
{
	if (cube_mlx_init(c) == -1)
	{
		ft_close(c);
		return (-1);
	}
	mlx_hook(c->win->reference, 2, 0, key_down, c);
	mlx_hook(c->win->reference, 3, 0, key_up, c);
	mlx_hook(c->win->reference, 17, 1L << 2, ft_close, c);
	mlx_loop_hook(c->mlx, loop_hook, c);
	mlx_loop(c->mlx);
	return (0);
}
