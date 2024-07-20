/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:54:50 by aalvarez          #+#    #+#             */
/*   Updated: 2024/07/20 15:25:50 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int		written;

	written = 0;
	while (*format)
	{
		written += write(STDOUT_FILENO, format, 1);
		format++;
	}
	return (written);
}
