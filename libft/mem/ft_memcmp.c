/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:18:51 by aucousin          #+#    #+#             */
/*   Updated: 2022/09/28 18:28:49 by aucousin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = p1;
	b = p2;
	while (size--)
	{
		if (*a != *b)
			return (*a - *b);
		++a;
		++b;
	}
	return (0);
}
