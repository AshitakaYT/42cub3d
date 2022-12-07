/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:06:33 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:50:19 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	cube_mlx_init(t_cube *c)
{
	t_image	*img;

	c->is_grabing = 0;
	c->grab_x = 0;
	c->grab_y = 0;
	c->key_backward = 0;
	c->key_forward = 0;
	c->key_strafe_right = 0;
	c->key_strafe_left = 0;
	c->key_display_map = 0;
	c->display_map = 0;
	c->key_rotate_right = 0;
	c->key_rotate_left = 0;
	c->key_open = 0;
	c->mlx = mlx_init();
	c->starting_time = get_time();
	c->win = ft_new_window(c->mlx, (950),
			(600), "./cub3d");
	img = malloc(sizeof(t_image));
	if (!img || !c->win)
		return (-1);
	c->img = img;
	if (ft_create_sprites(c) == -1 || cube_mlx_initplayer(c) == -1)
		return (-1);
	return (0);
}

int	cube_mlx_initplayer2(t_cube *c, int i, int j)
{
	c->ma->p->x = j * SIZE + (SIZE / 2);
	c->ma->p->y = i * SIZE + (SIZE / 2);
	if (c->ma->tab[i][j] == 'E')
		c->ma->p->a = 0;
	if (c->ma->tab[i][j] == 'N')
		c->ma->p->a = 3 * PI / 2;
	if (c->ma->tab[i][j] == 'W')
		c->ma->p->a = PI;
	if (c->ma->tab[i][j] == 'S')
		c->ma->p->a = PI / 2;
	c->ma->p->dx = cos(c->ma->p->a);
	c->ma->p->dy = sin(c->ma->p->a);
	return (0);
}

int	cube_mlx_initplayer(t_cube *c)
{
	int	i;
	int	j;

	c->ma->p = malloc(sizeof(t_player));
	if (!c->ma->p)
		return (-1);
	i = 0;
	while (c->ma->tab[i])
	{
		j = 0;
		while (c->ma->tab[i][j])
		{
			if (ft_isincharset(c->ma->tab[i][j], "NSWE"))
			{
				cube_mlx_initplayer2(c, i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}
