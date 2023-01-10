/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:08:04 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/10 10:32:11 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

void	printstring(va_list *vl)
{
	char	*string;
	int		i;

	i = 0;
	string = va_arg(*vl, char *);
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
}

void	format(const char *fmt, char c, va_list *vl, int i)
{
	char	chr;

	if (c == 'c')
	{
		chr = va_arg(*vl, int);
		write(1, &chr, 1);
	}
	if (c == 's')
		printstring(vl);
	if (c == 'i')
		printint(va_arg(*vl, int), 1);
	if (c == 'd')
		printint(va_arg(*vl, int), 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
	i++;
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	vl;
	int		i;

	i = 0;
	va_start(vl, fmt);
	while (fmt && fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			format(fmt, fmt[i], &vl, i);
		}
		else
		{
			write(1, &fmt[i], 1);
		}
		i++;
	}
	va_end(vl);
	return (i);
}

int	main(void)
{
	char	p;

	p = 'p';
	ft_printf("test%c %s %i", p, "test", -10);
}
