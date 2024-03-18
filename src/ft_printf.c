/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:26:58 by aalvarez          #+#    #+#             */
/*   Updated: 2024/03/18 23:34:46 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int	written;

	written = 0;
	while (*format)
	{
		written += (int)write(1, format++, 1);
	}
	return (written);
}
