/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:33:54 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/24 12:51:14 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_string(const char *s, int k, va_list vl, t_flags *fl)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			k += 1;
		}
		if (s[i] == '%' && s[i + 1])
		{
			i += parse_flags(fl, (s + i), vl);
			if (fl->type == 0)
				break ;
			k += write_flag(fl, vl);
		}
		i++;
	}
	return (k);
}

int		ft_printf(const char *s, ...)
{
	va_list		vl;
	int			k;
	t_flags		fl;

	va_start(vl, s);
	k = 0;
	k = parse_string(s, k, vl, &fl);
	va_end(vl);
	return (k);
}
