/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:53:18 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/06 09:29:26 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr_uns;

	if (n < 0)
	{
		nbr_uns = (unsigned int)(-1 * n);
		ft_putchar_fd('-', fd);
	}
	else
		nbr_uns = (unsigned int)n;
	if (nbr_uns >= 10)
	{
		ft_putnbr_fd(nbr_uns / 10, fd);
		ft_putnbr_fd(nbr_uns % 10, fd);
	}
	else
		ft_putchar_fd(nbr_uns + '0', fd);
}
