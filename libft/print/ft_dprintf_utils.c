/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:42:24 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:56:37 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_convert_base_dprintf(unsigned long long nbr,
								char *base, int bytes, int fd)
{
	unsigned int	len;

	len = 0;
	bytes++;
	while (base[len])
		len++;
	if (nbr >= len)
		bytes = ft_convert_base_dprintf(nbr / len, base, bytes, fd);
	ft_putchar_dprintf(fd, base[nbr % len]);
	return (bytes);
}

int	ft_pnb_dprintf(int nbr, char *base, int bytes, int fd)
{
	long long int	nbr2;
	int				lenbase;

	lenbase = 0;
	while (base[lenbase])
		lenbase++;
	nbr2 = nbr;
	if (ft_check_base(base))
	{
		if (nbr2 < 0)
		{
			ft_putchar_dprintf(fd, '-');
			nbr2 *= -1;
			bytes++;
		}
		bytes = ft_convert_base_dprintf(nbr2, base, bytes, fd);
	}
	return (bytes);
}

int	ft_pnbu_dprintf(unsigned int nbr, char *base, int bytes, int fd)
{
	long long int	nbr2;
	int				lenbase;

	lenbase = 0;
	while (base[lenbase])
		lenbase++;
	nbr2 = nbr;
	if (ft_check_base(base))
	{
		if (nbr2 < 0)
		{
			nbr2 = 4294967296 + nbr;
			bytes++;
		}
		bytes = ft_convert_base_dprintf(nbr2, base, bytes, fd);
	}
	return (bytes);
}

int	ft_putnbrbase_ptr_dprintf(long long nbr, char *base, int bytes, int fd)
{
	unsigned long long int	nbr2;
	int						lenbase;

	lenbase = 0;
	while (base[lenbase])
		lenbase++;
	if (nbr == -9223372036854775807)
	{
		nbr2 = LONG_MAX;
		nbr2++;
	}
	else
	nbr2 = nbr;
	if (ft_check_base(base))
	{
		if (nbr2 < 0)
		{
			nbr2 = LONG_MAX + nbr;
			bytes++;
		}
		bytes = ft_convert_base_dprintf(nbr2, base, bytes, fd);
	}
	return (bytes);
}

int	ft_putptr_dprintf(long long p, int fd)
{
	int	bite;

	bite = ft_putstr_dprintf(fd, "0x");
	bite += ft_putnbrbase_ptr_dprintf(p, "0123456789abcdef", 0, fd);
	return (bite);
}
