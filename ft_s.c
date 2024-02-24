/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:20:02 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/02/24 13:20:02 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int ft_str_prec(char *s, int prec)
{
    int i;

    i = -1;
    while (s[i] && i < prec)
        write(1, &s[++i], 1);
    return (i);
}

static int ft_putstr(char *s)
{
    int i;

    if (s == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    i = 0;
    write(1, s, ft_strlen((char *)s));
    return (i);
}

static int ft_s(char *s, t_options opts)
{
    int i;

    i = 0;
    if (opts.prec >= 0)
    {
        i += opt_pad(opts.prec, ft_strlen(s), 0);
        i += ft_str_prec(s, opts.prec);
    }
    return (i);
}

int	ft_prnts(char *s, t_options opts)
{
	int	i;

	i = 0;
    if (!s && opts.prec >= 0 && opts.prec < 6)
       return (i += opt_pad(opts.width, 0, 0));
	if (!s)
		s = "(null)";
    if (opts.prec >= 0 && (size_t)opts.prec > ft_strlen(s))
        opts.prec = ft_strlen((char *)s);
    if (opts.left == 1)
        i += ft_s(s, opts);
    if (opts.prec >= 0)
        i += opt_pad(opts.width, opts.prec, 0);
    else 
        i += opt_pad(opts.width, ft_strlen(s), 0);
    if (opts.left == 0)
        i += ft_s(s, opts);
	return (i);
}
