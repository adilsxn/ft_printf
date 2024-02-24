/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:01:16 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/02/24 12:01:16 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

t_options opt_left(t_options opts)
{
    opts.zero = 0;
    opts.left = 1;
    return (opts);
}

t_options opt_digit(char c, t_options opts)
{
    if (opts.star == 1)
        opts.width = 0;
    opts.width = (opts.width * 10) + (c - '0');
    return (opts);
}

t_options opt_width(va_list args, t_options opts)
{
    opts.star = 1;
    opts.width = va_arg(args, int);
    if (opts.width < 0)
    {
        opts.width *= -1;
        opts.left = 1;
    }
    return (opts);
}

int opt_prec(const char *s, int pos, va_list args, t_options *opts)
{
    int i;

    i = pos + 1;
    if (s[i] == '*')
    {
        opts->prec = va_arg(args, int);
        i++;
        return (i);
    }
    opts->prec = 0;
    while(s[i] >= '0' && s[i] <= '9')
        opts->prec = (opts->prec * 10) + (s[i++] - 0);
    return (i);
}

int opt_pad(int width, int size, int zero)
{
    int length;

    length = 0;
    while (width - size > 0)
    {
        if (zero)
            length += ft_c('0');
        else
            length += ft_c(' ');
        width--;
    }
    return (length);
}

