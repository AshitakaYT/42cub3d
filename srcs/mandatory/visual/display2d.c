/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:14:10 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 07:38:59 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

void	cube_player_print(t_cube *c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i <= 4)
	{
		while (j <= 4)
		{
			my_mlx_pixel_put(c->img, (c->ma->p->x) \
			+ 68 + i, c->ma->p->y - 2 + j, 0xFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
}

void	cube_minimap_print(t_cube *c, int i, int j)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 12)
	{
		x = -1;
		while (x++ <= 12)
		{
			if (c->ma->tab[i][j] == '1')
				my_mlx_pixel_put(c->img, (j * SIZE) + x + 70,
					(i * SIZE) + y, 0xFFFFFF);
			else if (c->ma->tab[i][j] == 'P')
				my_mlx_pixel_put(c->img, (j * SIZE) + x + 70,
					(i * SIZE) + y, 0x0000FF);
			else if (c->ma->tab[i][j] == '0' ||
			ft_isincharset(c->ma->tab[i][j], "NSEW"))
				my_mlx_pixel_put(c->img, (j * SIZE) + x + 70,
					(i * SIZE) + y, 0x00000);
			else if (c->ma->tab[i][j] == '2')
				my_mlx_pixel_put(c->img, (j * SIZE) + x + 70,
					(i * SIZE) + y, 0x0FF00);
		}
		y++;
	}
}

void	cube_minimap(void *param)
{
	t_cube	*c;

	c = (t_cube *)param;
	c->img->img = mlx_new_image(c->mlx, (1440), (1080));
	c->img->addr = mlx_get_data_addr(c->img->img, &c->img->bits_per_pixel,
			&c->img->line_size, &c->img->endian);
	c->img->size.x = 1440;
	c->img->size.y = 1000;
	cube_display_rays(c);
	mlx_put_image_to_window(c->mlx, c->win->reference, c->img->img, 0, 0);
	mlx_destroy_image(c->mlx, c->img->img);
}
