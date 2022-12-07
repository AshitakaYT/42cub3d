/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printreturn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:36:46 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:56:18 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_printreturn(char *str, int fd, int ret)
{
	write(fd, str, ft_strlen(str));
	return (ret);
}
