/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:45:23 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/09 16:27:05 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == uc)
			return ((void *)tmp + i);
		i++;
	}
	return (0);
}
