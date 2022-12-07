/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:19:47 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 17:22:13 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs/cub3d.h"

int	cube_init(t_cube *c)
{
	c->ma = NULL;
	c->el = NULL;
	c->map = NULL;
	return (0);
}

int	cube_parsing(int ac, char **av, t_cube *c)
{
	if (ac != 2)
		return (ft_printreturn("Error. parsing: \
		Wrong number of arguments.\n", 2, -1));
	if (ft_strendby(av[1], ".cub") == -1)
		return (ft_printreturn("Error. parsing: \
		Map must be in format '.cub'\n", 2, -1));
	if (cube_openmap(c, av[1]) == -1)
		return (ft_printreturn("Error. parsing: openmap failed.\n", 2, -1));
	if (cube_initparsing(c) == -1)
		return (ft_printreturn("Error. parsing: initmap failed.\n", 2, -1));
	if (cube_getelems(c) == -1)
		return (ft_printreturn("Error. parsing: getelems failed.\n", 2, -1));
	if (cube_getmap(c) == -1)
		return (ft_printreturn("Error. parsing: getmap failed.\n", 2, -1));
	return (0);
}

int	main(int ac, char **av)
{
	t_cube	c;

	cube_init(&c);
	if (cube_parsing(ac, av, &c) != -1)
		cube_mlx(&c);
	else
		ft_printf("something went wrong.\n");
	cube_free(&c);
	return (0);
}
