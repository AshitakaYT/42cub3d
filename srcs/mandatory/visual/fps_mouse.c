/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:05:10 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/04 14:49:40 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"
/*
void	cube_fps_print(t_cube *c, char *string)
{
	mlx_put_image_to_window(c->mlx, c->win->reference, c->ma->fps_banner.img,
		0, 0);
	mlx_string_put(c->mlx, c->win->reference,
		0, 10, 0xffffff, "FPS: ");
	mlx_string_put(c->mlx, c->win->reference,
		38, 10, 0xffffff, string);
	mlx_string_put(c->mlx, c->win->reference,
		0, 20, 0xffffff, "W Forward");
	mlx_string_put(c->mlx, c->win->reference,
		0, 30, 0xffffff, "S Backward");
	mlx_string_put(c->mlx, c->win->reference,
		0, 40, 0xffffff, "D Right");
	mlx_string_put(c->mlx, c->win->reference,
		0, 50, 0xffffff, "A Left");
	mlx_string_put(c->mlx, c->win->reference,
		0, 60, 0xffffff, "Esc Exit");
}

int	ft_fps(t_cube *c)
{
	static int		lframe;
	static int		frame;
	static int64_t	fps;
	char			*string;

	if (get_time() - fps < 1000)
	{
		frame++;
	}
	else
	{
		lframe = frame;
		fps = get_time();
		frame = 1;
	}
	string = ft_itoa(lframe);
	cube_fps_print(c, string);
	free(string);
	return (0);
}

int	mouse_pressed(int button, int x, int y, t_cube *c)
{
	(void)button;
	c->is_grabing = 1;
	c->grab_x = x;
	c->grab_y = y;
	c->last_mouse_x = x;
	mlx_mouse_hide();
	return (0);
}

int	mouse_release(int button, int x, int y, t_cube *c)
{
	(void)button;
	(void)y;
	(void)x;
	c->is_grabing = 0;
	mlx_mouse_show();
	return (0);
}

int	mouse_moving(int x, int y, t_cube *c)
{
	int	delta_x;

	(void)y;
	if (c->is_grabing == 1)
	{
		delta_x = x - c->grab_x;
		mlx_mouse_move(c->win->reference, c->grab_x, c->grab_y);
		c->ma->p->a += delta_x * 0.001;
		c->ma->p->dx = cos(c->ma->p->a);
		c->ma->p->dy = sin(c->ma->p->a);
	}
	return (0);
}
*/
