/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:59:37 by aalvarez          #+#    #+#             */
/*   Updated: 2021/07/29 14:42:40 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_cflag(int c);
int	ft_sflag(char *s);
int	ft_uxXflag(unsigned long long num, char c);
int	ft_diflag(long num);
int	ft_checkflags(int i, const char *str, va_list flags);
int	hexa_flags(char c, va_list flags, const char *str, int i);
int	number_flags(char c, va_list flags);
int	text_flags(char c, va_list flags);

#endif
