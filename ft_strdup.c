/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:57:25 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/02/24 10:57:25 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void *ft_memcpy(void *dst, const void *src, size_t len)
{
    char *d;
    const char *s;

    if (!dst && !src)
        return (0);
    d = dst;
    s = src;
    while(len-- > 0)
        *d++ = *s++;
    return (dst);
}

int ft_strlen(char *str)
{
    int len;

    if (!str || *str == '\0')
        return (0);
    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

char	*ft_strdup(char *src)
{
	char	*dupl;

	dupl = malloc(ft_strlen(src) + 1);
	if (!dupl)
		return (NULL);
	ft_memcpy(dupl, src, (ft_strlen(src) + 1));
	return (dupl);
}
