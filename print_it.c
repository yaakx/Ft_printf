/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:24:19 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/24 14:28:18 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minus_zero(t_flags *fl, int n)
{
	int k;

	k = 0;
	if (fl->zero == 1 && fl->precision == -1 && fl->minus == -1 && n < 0)
	{
		write(1, "-", 1);
		k = 1;
	}
	if (fl->zero == 1 && fl->precision == -1
			&& fl->minus == -1 && fl->type == 'p')
	{
		write(1, "0x", 2);
		k = 1;
	}
	return (k);
}

int		minus_zero_alter(t_flags *fl, int n, int k, int i)
{
	if (n < 0 && k == 0)
	{
		write(1, "-", 1);
		i++;
	}
	else if (k == 1 && fl->type != 'p')
		i++;
	if (fl->type == 'p' && k == 0)
	{
		write(1, "0x", 2);
		i = i + 2;
	}
	else if (k == 1 && fl->type == 'p')
		i += 2;
	return (i);
}

int		write_precision_arg(t_flags *fl, char *s, int i)
{
	int k;
	int j;

	k = 0;
	j = (fl->precision > (int)ft_strlen(s)) ?
		fl->precision - (int)ft_strlen(s) : 0;
	j = (ft_strlen(s) > 0) ? j : 0;
	while (k++ < j)
	{
		write(1, "0", 1);
		i++;
	}
	j = 0;
	while (s[j] != 0 && fl->precision != 0)
	{
		write(1, &s[j++], 1);
		i++;
	}
	return (i);
}

void	print_it(t_flags *fl, int n, int len, char *s)
{
	int	j;
	int i;
	int k;

	if (len == 0)
		return ;
	j = (fl->precision > (int)ft_strlen(s)) ? fl->precision : (int)ft_strlen(s);
	j = (n < 0) ? j + 1 : j;
	i = 0;
	k = minus_zero(fl, n);
	while (fl->minus == -1 && i < (fl->width - j))
	{
		if (fl->zero == 1 && fl->precision == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	i = minus_zero_alter(fl, n, k, i);
	i = write_precision_arg(fl, s, i);
	while (i++ < len)
		write(1, " ", 1);
}
