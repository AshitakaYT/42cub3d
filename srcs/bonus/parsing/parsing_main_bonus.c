/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:32:51 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 17:25:52 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

char	*ft_fullfill_tabcub(char *path, char buf, int size)
{
	int		fd;
	char	*res1;

	res1 = malloc(sizeof(char) * size + 1);
	if (!res1)
		return (0);
	size = 0;
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1))
	{
		res1[size] = buf;
		size++;
	}
	res1[size] = '\0';
	close(fd);
	return (res1);
}

char	*ft_readfilecub(char *path)
{
	int		fd;
	int		size;
	char	buf;

	buf = '\0';
	size = 0;
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (0);
	ft_dprintf(2, "Calculating map size...\n");
	while (read(fd, &buf, 1))
	{
		size++;
		if (size > 100000)
		{
			ft_dprintf(2, "error: please input a 100x1000 max map.\n");
			close (fd);
			return (NULL);
		}
	}
	ft_dprintf(2, "Valid map size !\nParsing...\n");
	if (close(fd) == -1)
		return (0);
	return (ft_fullfill_tabcub(path, buf, size));
}

int	cube_openmap(t_cube *c, char *file)
{
	char	*readfile;

	readfile = ft_readfilecub(file);
	if (!readfile)
		return (ft_printreturn("error: cube_openmap: \
		ft_readfile failed.\n", 2, -1));
	if (cube_checkmap_newline(readfile, '\n', 7) == -1)
	{
		free(readfile);
		return (ft_printreturn("error: cube_openmap: \
		checkmap newline failed.\n", 2, -1));
	}
	c->map = ft_split(readfile, '\n');
	free(readfile);
	if (!c->map)
		return (ft_printreturn("error: cube_openmap: \
		ft_split failed.\n", 2, -1));
	return (0);
}

int	cube_malloc_elem(t_cube *c)
{
	c->el = malloc(sizeof(t_elem));
	if (!c->el)
		return (-1);
	c->el->ce = NULL;
	c->el->fl = NULL;
	c->el->no = NULL;
	c->el->so = NULL;
	c->el->we = NULL;
	c->el->ea = NULL;
	c->el->po = NULL;
	return (0);
}

int	cube_initparsing(t_cube *c)
{
	char	**tmp;

	tmp = c->map;
	if (ft_tablen(c->map) < 10)
		return (ft_printreturn("invalid map.\n", 2, -1));
	cube_malloc_elem(c);
	c->el->elems = ft_subtab(c->map, 0, 7);
	if (!c->el->elems)
		return (ft_printreturn("subtab failed.\n", 2, -1));
	c->map = ft_subtab(tmp, 7, ft_tablen(tmp) - 7);
	ft_freetab(tmp);
	if (!c->map)
		return (ft_printreturn("subtab failed.\n", 2, -1));
	return (0);
}
