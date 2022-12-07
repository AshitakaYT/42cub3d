/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:52:43 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:18:02 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe something */

int	straf_right(t_cube *c)
{
	float	direction_x;
	float	direction_y;

	direction_x = cos(c->ma->p->a - M_PI / 2) * 0.5;
	direction_y = sin(c->ma->p->a - M_PI / 2) * 0.5;
	if ((int)(c->ma->p->x) / SIZE >= 0
	&& (int)(c->ma->p->x) / SIZE < c->ma->wid
	&& (int)(c->ma->p->y - direction_y) / SIZE >= 0
	&& (int)(c->ma->p->y - direction_y) / SIZE < c->ma->hei
	&& !ft_isincharset(c->ma->tab
	[(int)(c->ma->p->y - (direction_y * 5)) / SIZE]
	[(int)(c->ma->p->x) / SIZE], "1P"))
		c->ma->p->y -= direction_y;
	if ((int)(c->ma->p->x - direction_x) / SIZE >= 0
	&& (int)(c->ma->p->x - direction_x) / SIZE < c->ma->wid
	&& (int)(c->ma->p->y) / SIZE >= 0
	&& (int)(c->ma->p->y) / SIZE < c->ma->hei
	&& !ft_isincharset(c->ma->tab
	[(int)(c->ma->p->y) / SIZE]
	[(int)(c->ma->p->x - (direction_x * 5)) / SIZE], "1P"))
		c->ma->p->x -= direction_x;
	return (0);
}

int	straf_left(t_cube *c)
{
	float	direction_x;
	float	direction_y;

	direction_x = cos(c->ma->p->a + M_PI / 2) * 0.5;
	direction_y = sin(c->ma->p->a + M_PI / 2) * 0.5;
	if ((int)(c->ma->p->x) / SIZE >= 0
	&& (int)(c->ma->p->x) / SIZE < c->ma->wid
	&& (int)(c->ma->p->y - direction_y) / SIZE >= 0
	&& (int)(c->ma->p->y - direction_y) / SIZE < c->ma->hei
	&& !ft_isincharset(c->ma->tab
	[(int)(c->ma->p->y - (direction_y * 10)) / SIZE]
	[(int)(c->ma->p->x) / SIZE], "1P"))
		c->ma->p->y -= direction_y;
	if ((int)(c->ma->p->x - direction_x) / SIZE >= 0
	&& (int)(c->ma->p->x - direction_x) / SIZE < c->ma->wid
	&& (int)(c->ma->p->y) / SIZE >= 0
	&& (int)(c->ma->p->y) / SIZE < c->ma->hei
	&& !ft_isincharset(c->ma->tab
	[(int)(c->ma->p->y) / SIZE]
	[(int)(c->ma->p->x - (direction_x * 10)) / SIZE], "1P"))
		c->ma->p->x -= direction_x;
	return (0);
}

int	cube_input(int key, void *param)
{
	t_cube	*c;

	c = (t_cube *)param;
	if (key == 53)
		ft_close(c);
	else if (key == 46)
	{
		if (c->display_map == 1)
			c->display_map = 0;
		else if (c->display_map == 0)
			c->display_map = 1;
	}
	return (0);
}

int	key_down(int key, t_cube *c)
{
	if (key == 13)
		c->key_forward = 1;
	else if (key == 1)
		c->key_backward = 1;
	else if (key == 2)
		c->key_strafe_right = 1;
	else if (key == 0)
		c->key_strafe_left = 1;
	else if (key == 124)
		c->key_rotate_right = 1;
	else if (key == 123)
		c->key_rotate_left = 1;
	else if (key == 49)
		cube_open_close_door(c);
	else
		cube_input(key, c);
	return (0);
}

int	key_up(int key, t_cube *c)
{
	if (key == 13)
		c->key_forward = 0;
	else if (key == 1)
		c->key_backward = 0;
	else if (key == 2)
		c->key_strafe_right = 0;
	else if (key == 0)
		c->key_strafe_left = 0;
	else if (key == 46)
		return (0);
	else if (key == 124)
		c->key_rotate_right = 0;
	else if (key == 123)
		c->key_rotate_left = 0;
	else if (key == 49)
		c->key_open = 0;
	else
		cube_input(key, c);
	return (0);
}
