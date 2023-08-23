/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:16:18 by acuva-nu          #+#    #+#             */
/*   Updated: 2022/12/01 18:11:37 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_c(int c);
int	ft_s(const char *str);
int	ft_di(int n);
int	ft_u(unsigned int n);
int	ft_hexing(unsigned long int n, char *b);
int	ft_x(unsigned int n, char c);
int	ft_p(unsigned int long n);
int	ft_printf(const char *fmt, ...);

#endif
