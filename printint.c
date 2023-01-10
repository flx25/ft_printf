/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:18 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/10 10:27:21 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libftprintf.h"

static void	writedigits(int n, int fd)
{
	char	c;

	if (n >= 10)
	{
		writedigits(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	printint(int n, int fd)
{
	char	minus;

	minus = '-';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, &minus, 1);
		writedigits(n * -1, fd);
	}
	else
		writedigits(n, fd);
}
