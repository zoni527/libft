/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:51:40 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/04 11:53:19 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_recursive_putnbr_fd(long n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	ft_recursive_putnbr_fd(n, fd);
}

static	void	ft_recursive_putnbr_fd(long n, int fd)
{
	int		mod;
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		ft_recursive_putnbr_fd(-n, fd);
		return ;
	}
	if (n >= 10)
		ft_recursive_putnbr_fd(n / 10, fd);
	mod = n % 10;
	c = mod + '0';
	write(fd, &c, 1);
}
