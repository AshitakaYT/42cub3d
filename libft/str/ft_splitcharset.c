/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcharset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:31:27 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/06 08:55:15 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_is_in_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	dest = malloc((j + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < j && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_len_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_in_charset(charset, str[i]))
		i++;
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_in_charset(charset, str[i]))
		{
			i++;
		}
		if (str[i] && !ft_is_in_charset(charset, str[i]))
		{
			count++;
			i += ft_len_word(&str[i], charset);
		}
	}
	return (count);
}

char	**ft_splitcharset(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = malloc(sizeof (char *) * (ft_count_words(str, charset) + 1));
	if (!split)
		return (NULL);
	while (i < ft_count_words(str, charset))
	{
		while (str[j] && ft_is_in_charset(charset, str[j]))
			j++;
		if (str[j])
		{
			split[i] = ft_strndup(&str[j], ft_len_word(&str[j], charset));
			if (!split[i])
				return (NULL);
			j += ft_len_word(&str[j], charset);
		}
		i++;
	}
	split[i] = malloc(1 * sizeof(char));
	split[i] = 0;
	return (split);
}
