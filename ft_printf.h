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


t_options opt_left(t_options opts);
int opt_pad(int width, int size, int zero);
t_options opt_digit(char c, t_options opts);
t_options opt_width(va_list args, t_options opts);
int opt_prec(const char *s, int pos, va_list args, t_options *opts);
//-----------//
int is_opt(int c);
int is_kind(int c);
int is_spec(int c);
//----------//
int ft_isdigit(int c);
int ft_strlen(char *str);
char *ft_strdup(const char *src);
int ft_par(char *s, va_list args);
//---------//
int	ft_c(int c);
int ft_prntc(int c, t_options opts);
//--------//
int	ft_di(int n);
int	ft_u(unsigned int n);
int	ft_hexing(unsigned long int n, char *b);
int	ft_x(unsigned int n, char c);
int	ft_p(unsigned int long n);
int	ft_printf(const char *fmt, ...);

#endif
