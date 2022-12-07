/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:49:36 by aucousin          #+#    #+#             */
/*   Updated: 2022/09/28 18:28:49 by aucousin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;

	n = 0;
	while (n < len)
	{
		*(unsigned char *)b = c;
		b++;
		n++;
	}
	return (b - n);
}
