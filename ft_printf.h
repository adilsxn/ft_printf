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
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_options
{
    int spec;
    int width;
    int zero;
    int hash;
    int space;
    int plus;
    int left;
    int star;
    int prec;
} t_options;

int ft_strlen(char *str);
char *ft_strdup(const char *src);
int	ft_c(int c);
int	ft_s(const char *str);
int	ft_di(int n);
int	ft_u(unsigned int n);
int	ft_hexing(unsigned long int n, char *b);
int	ft_x(unsigned int n, char c);
int	ft_p(unsigned int long n);
int	ft_printf(const char *fmt, ...);

#endif
