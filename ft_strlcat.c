/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:16:01 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/09 14:25:51 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dl;
	size_t	sl;
	size_t	res;

	i = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dl < dstsize)
		res = dl + sl;
	else
		res = sl + dstsize;
	if (dstsize == 0)
		return (res);
	while (src[i] && dl + i < dstsize - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (res);
}
