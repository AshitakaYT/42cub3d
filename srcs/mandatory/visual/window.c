/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:54:17 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 17:21:48 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

int	ft_close(t_cube *c)
{
	if (c != NULL)
		mlx_destroy_window(c->mlx, c->win->reference);
	cube_free(c);
	exit(EXIT_SUCCESS);
}

t_window	*ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->reference = mlx_new_window(mlx, 1440, 1000, name);
	window->size.x = widht;
	window->size.y = height;
	mlx_hook(window->reference, 17, 0, ft_close, 0);
	return (window);
}
