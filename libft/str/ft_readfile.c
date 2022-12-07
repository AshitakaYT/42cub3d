/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:41:32 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 09:37:16 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

char	*ft_fullfill_tab(int fd, char *res1, char buf)
{
	int	size;

	size = 0;
	while (read(fd, &buf, 1))
	{
		res1[size] = buf;
		size++;
	}
	res1[size] = '\0';
	return (res1);
}

char	*ft_readfile(char *path)
{
	int		fd;
	char	*res1;
	int		size;
	char	buf;

	buf = '\0';
	size = 0;
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1))
		size++;
	res1 = malloc(sizeof(char) * size + 1);
	if (!res1)
		return (0);
	if (close(fd) == -1)
		return (0);
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (0);
	res1 = ft_fullfill_tab(fd, res1, buf);
	close(fd);
	return (res1);
}
