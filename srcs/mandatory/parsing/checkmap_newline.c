/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:55:27 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 17:31:25 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/cub3d.h"

static int	ft_len_word(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == charset))
		i++;
	return (i);
}

static int	ft_count_word(char const *str, char charset, int nb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && count < nb)
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] && !(str[i] == charset))
		{
			count++;
			i += ft_len_word(&str[i], charset);
		}
	}
	if (count != nb)
		return (-1);
	return (i);
}

int	ft_mapstart(char const *str, char charset, int nb)
{
	if (!str)
		return (-1);
	return (ft_count_word(str, charset, nb));
}

int	ft_mapend(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && str[i - 1] == '\n')
	{
		i--;
	}
	return (i);
}

int	cube_checkmap_newline(char *str, char charset, int nb)
{
	int		i;
	char	tmp;
	int		end;

	i = ft_mapstart(str, charset, nb);
	if (i == -1)
		return (-1);
	while (str[i] && str[i] == '\n')
		i++;
	tmp = '\0';
	end = ft_mapend(str);
	ft_printf("start = %d\nend = %d\n", i, end);
	while (str[i] && i < end)
	{
		if (str[i] == '\n' && tmp == '\n')
			return (ft_printreturn("Error: newline in map.\n", 2, -1));
		tmp = str[i];
		i++;
	}
	return (0);
}
