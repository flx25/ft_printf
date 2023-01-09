/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:08:04 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/09 17:13:25 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	format(const char *fmt, char c, va_list *vl, int i)
{
	char	chr;

	if (c == 'c')
	{
		chr = va_arg(*vl, int);
		write(1, &chr, 1);
	}

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
	ft_printf("test%c", p);
}
