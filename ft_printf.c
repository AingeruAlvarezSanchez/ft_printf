/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:57:10 by aalvarez          #+#    #+#             */
/*   Updated: 2021/07/30 11:18:08 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_checkflags(int i, const char *str, va_list flags)
{
	int	j;

	j = 0;
	if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%')
		j += text_flags(str[i + 1], flags);
	if (str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u')
		j += number_flags(str[i + 1], flags);
	if (str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == 'p')
		j += hexa_flags(str[i + 1], flags, str, i);
	return (j);
}

int	hexa_flags(char c, va_list flags, const char *str, int i)
{
	int	j;

	j = 0;
	if (c == 'x' || c == 'X')
		j += ft_uxXflag(va_arg(flags, unsigned int), str[i + 1]);
	else
		j += ft_uxXflag(va_arg(flags, uintptr_t), str[i + 1]);
	return (j);
}

int	number_flags(char c, va_list flags)
{
	int	j;

	j = 0;
	if (c == 'u')
		j += ft_diflag(va_arg(flags, unsigned int));
	else
		j += ft_diflag(va_arg(flags, int));
	return (j);
}

int	text_flags(char c, va_list flags)
{
	int	j;

	j = 0;
	if (c == '%')
	{
		write(1, "%", 1);
		j++;
	}
	if (c == 'c')
		j += ft_cflag(va_arg(flags, int));
	if (c == 's')
		j += ft_sflag(va_arg(flags, char *));
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	flags;
	int		i;
	int		j;

	if (!str)
		return (0);
	va_start(flags, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
		{
			write(1, &str[i], 1);
			j++;
		}
		if (str[i] == '%')
		{
			j += ft_checkflags(i, str, flags);
			i++;
		}
		i++;
	}
	va_end(flags);
	return (j);
}
