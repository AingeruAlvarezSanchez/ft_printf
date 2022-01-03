/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:01:32 by aalvarez          #+#    #+#             */
/*   Updated: 2021/07/29 14:40:16 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_diflag_op(long num2)
{
	if (num2 > 9)
	{
		ft_diflag_op(num2 / 10);
		ft_diflag_op(num2 % 10);
	}
	else
	{
		num2 = num2 + 48;
		write(1, &num2, 1);
	}
}

int	ft_isneg(long count, int j)
{
	j = 1;
	if (count < 0)
	{
		j++;
		count = count * -1;
	}
	return (j);
}

int	ft_diflag(long num)
{
	int		j;
	long	num2;
	long	count;

	count = num;
	j = ft_isneg(count, j);
	if (j == 2)
		count *= -1;
	while (count > 9)
	{
		j++;
		count /= 10;
	}
	if (num < 0)
	{
		num2 = num * -1;
		write(1, "-", 1);
		ft_diflag_op(num2);
	}
	else
	{
		num2 = num;
		ft_diflag_op(num2);
	}
	return (j);
}

static void	ft_uxXflag_op(unsigned long long num, int Xx)
{
	if (num > 15)
	{
		ft_uxXflag_op(num / 16, Xx);
		ft_uxXflag_op(num % 16, Xx);
	}
	else
	{
		if (num > 9)
			num = num + Xx;
		num = num + 48;
		write(1, &num, 1);
	}
}

int	ft_uxXflag(unsigned long long num, char c)
{
	unsigned long long	count;
	int					j;

	j = 1;
	count = num;
	while (count > 15)
	{
		j++;
		count /= 16;
	}
	if (c == 'p')
	{
		write(1, "0x", 2);
		j += 2;
	}
	if (c == 'X')
		ft_uxXflag_op(num, 7);
	else
		ft_uxXflag_op(num, 39);
	return (j);
}
