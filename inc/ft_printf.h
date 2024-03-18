/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:46:45 by aalvarez          #+#    #+#             */
/*   Updated: 2024/03/18 23:46:47 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by aalvarez on 3/18/24.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __GNUC__

int	ft_printf(const char *format, ...)
	__attribute__((format(printf, 1, 2)));

# endif

#endif //FT_PRINTF_H
