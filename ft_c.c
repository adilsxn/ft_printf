/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:09 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/02/24 13:05:09 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_prntc(int c, t_options opts)
{
    int size;

    size = 0;
    if (opts.left == 1)
        size += ft_c(c);
    size += opt_pad(opts.width, 1, opts.zero);
    if (opts.left == 0)
        size += ft_c(c);
    return (size);
}
