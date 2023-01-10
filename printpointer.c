/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:35:40 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/10 13:12:13 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

static void	writedigits(unsigned long n, int fd, int *wlen)
{
	char	c;

	if (n >= 10)
	{
		writedigits(n / 10, fd, wlen);
		c = n % 10 + '0';
		*wlen += write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		*wlen += write(fd, &c, 1);
	}
}

void	printpointer(void *ptr, int *wlen)
{
	wlen += write(1, "0x", 2);
	writedigits((unsigned long) ptr, 1, wlen);
}
