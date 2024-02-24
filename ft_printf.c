/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:15:15 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/01/31 20:23:16 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int par_opts(const char *s, int i, va_list args, t_options *opts)
{
    while (s[++i] && is_opt(s[i]))
    {
        if (s[i] == '-')
            *opts = opt_left(*opts);
        if (s[i] == '#')
            opts->hash = 1; 
        if (s[i] == '+')
            opts->plus = 1; 
        if (s[i] == ' ')
            opts->space = 1;
        if (s[i] == '0' && opts->left == 0 && opts->width == 0)
            opts->zero = 1; 
        if (s[i] == '.')
            i = opt_prec(s, i, args, opts);
        if (s[i] == '*')
            *opts = opt_width(args, *opts) ;
        if (ft_isdigit(s[i]))
            *opts = opt_digit(s[i], *opts);
        if (is_kind(s[i]))
        {
            opts->spec = s[i];
            break ;
        }
    }
    return (i);
}


int	ft_mng(int c, va_list *args, t_options opts)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_c((char)va_arg(*args, int));
	else if (c == 's')
		size += ft_s((char *)va_arg(*args, char *));
	else if (c == 'p')
		size += ft_p((unsigned long)va_arg(*args, unsigned long));
	else if (c == 'd')
		size += ft_di((int)va_arg(*args, int));
	else if (c == 'i')
		size += ft_di((int)va_arg(*args, int));
	else if (c == 'u')
		size += ft_u((unsigned int)va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			size += ft_x((unsigned int)va_arg(*args, unsigned int), 'x');
		else
			size += ft_x((unsigned int)va_arg(*args, unsigned int), 'X');
	}
	else if (c == '%')
		size += ft_c('%');
	return (size);
}

int ft_par(char *s, va_list args)
{
    int i;
    int j;
    int size;
    t_options opts;

    i = -1;
    size = 0;
    while(s[++i])
    {
        opts = (t_options){0, 0, 0, 0, 0, 0, 0 , 0, -1};
        if (s[i] == '%' && s[i + 1] != '\0')
        {
            j = par_opts(s, i, args, &opts);
            if(opts.spec > 0) 
                i = j;
            if (s[i] != '\0' && opts.spec > 0 && is_kind(s[i]))
                size += ft_mng(s[i], args, opts);
            else if (s[i] != '\0')
                size += ft_c(s[i], opts);
        }
        size += ft_c(s[i]);
    }
    return (size);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		size;
    char *s;

    if (!fmt || *fmt == '\0')
        return (0);
    s = ft_strdup(fmt);
	va_start(args, fmt);
	size = ft_par(s, args);
	va_end(args);
    free(s);
    return (size);
}
