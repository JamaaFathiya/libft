/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:47:55 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/09 19:45:23 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (flag == 1)
				count++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (count);
}

static void	*free_all(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(s[i++]);
	free(s);
	return (NULL);
}

static char	**fill(char const *a, char **s, char c, int index)
{
	int	j;
	int	offset;
	int	i;

	offset = 0;
	i = 0;
	while (i < count(a, c))
	{
		while (a[index] == c)
		{
			index++;
			offset++;
		}
		j = 0;
		while (a[index + j] != c && a[index + j])
			j++;
		s[i++] = ft_substr(a, offset, j);
		if (!s[--i])
			return (free_all(s, count(a, c)));
		i++;
		offset += j;
		index += j;
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		index;

	if (!s)
		return (0);
	index = 0;
	res = (char **) malloc((count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	res = fill(s, res, c, index);
	res[count(s, c)] = 0;
	return (res);
}
