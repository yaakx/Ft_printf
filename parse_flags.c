/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:00:49 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/24 13:21:58 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *fl)
{
	fl->minus = -1;
	fl->zero = -1;
	fl->width = -1;
	fl->precision = -1;
	fl->type = 0;
}

int		parse_flags_3(t_flags *fl, const char *s, va_list vl, int i)
{
	if (s[i] == '.')
	{
		fl->precision = 0;
		i++;
		if (s[i] == '*')
		{
			fl->precision = va_arg(vl, int);
			if (fl->precision < 0)
				fl->precision = -1;
			i++;
		}
		else
		{
			fl->precision = ft_atoi(s + i);
			while (s[i] <= '9' && s[i] >= '0')
				i++;
		}
	}
	if (s[i] != 0)
		fl->type = s[i];
	return (i);
}

int		parse_flags_2(t_flags *fl, const char *s, va_list vl, int i)
{
	if (s[i] == '*')
	{
		fl->width = va_arg(vl, int);
		if (fl->width < 0)
		{
			fl->width = fl->width * -1;
			fl->minus = 1;
		}
		i++;
	}
	if (s[i] <= '9' && s[i] >= '0')
	{
		fl->width = ft_atoi(s + i);
		while (s[i] <= '9' && s[i] >= '0')
			i++;
	}
	return (parse_flags_3(fl, s, vl, i));
}

int		parse_flags(t_flags *fl, const char *s, va_list vl)
{
	int		i;

	init_flags(fl);
	i = 1;
	if (s[i] == '-')
	{
		fl->minus = 1;
		i++;
	}
	while (s[i] == '0')
	{
		fl->zero = 1;
		i++;
	}
	if (s[i] == '-')
	{
		fl->minus = 1;
		i++;
	}
	return (parse_flags_2(fl, s, vl, i));
}
