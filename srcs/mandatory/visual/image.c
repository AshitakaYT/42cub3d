/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:18:38 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/04 14:41:12 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.img = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	img.intaddr = (unsigned int *)mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	img.addrsize = ft_strlen(img.addr);
	return (img);
}

int	ft_create_sprites(t_cube *c)
{
	c->ma->wall = ft_new_sprite(c->mlx, "./imgs/white12.xpm");
	c->ma->floor = ft_new_sprite(c->mlx, "./imgs/grey12.xpm");
	c->ma->player = ft_new_sprite(c->mlx, "./imgs/red4.xpm");
	c->ma->no = ft_new_sprite(c->mlx, c->el->no);
	c->ma->ea = ft_new_sprite(c->mlx, c->el->ea);
	c->ma->we = ft_new_sprite(c->mlx, c->el->we);
	c->ma->so = ft_new_sprite(c->mlx, c->el->so);
	if (!c->ma->no.img || !c->ma->ea.img || !c->ma->we.img
		|| !c->ma->so.img)
		return (-1);
	return (0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= data->size.x || y >= data->size.y)
		return ;
	dst = data->addr + (y * data->line_size + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
