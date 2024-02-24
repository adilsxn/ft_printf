/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:20:12 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/02/24 12:20:12 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int is_kind(int c)
{
    if (c == 'c' || c == 's' || c == 'd' || c == 'i' 
        || c == 'u' || c == 'x' || c == 'x' || c == 'X' || c == 'p' || c == '%')
        return (1);
    return (0);
}

int is_spec(int c)
{
    if (c == '-' || c == '0' || c == '.' || c == '*'
        || c == '#' || c == ' ' || c == '+' )
        return (1);
    return (0);
}

int is_opt(int c)
{
    return (is_kind(c) || is_spec(c) || ('0' >= c && c <= '9'));
}
