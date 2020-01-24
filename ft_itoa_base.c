/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:55:53 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/24 10:24:50 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fill_it(char *s, unsigned long long int n, int i, char type)
{
	char	*c;
	int		j;
	int		div;

	if (type == 'x')
		c = ft_strdup("0123456789abcdef");
	else if (type == 'X')
		c = ft_strdup("0123456789ABCDEF");
	else
		c = ft_strdup("0123456789");
	div = (type == 'x' || type == 'X') ? 16 : 10;
	s[i] = 0;
	i--;
	while (i >= 0)
	{
		j = (n > (div - 1)) ? (n % div) : n;
		s[i] = c[j];
		n = n / div;
		i--;
	}
	free(c);
	return (s);
}

char		*ft_itoa_base(unsigned long long int n, char type)
{
	int						i;
	unsigned long long int	c;
	char					*it;
	int						div;

	i = 0;
	div = (type == 'x' || type == 'X') ? 16 : 10;
	c = n;
	while (c > 0)
	{
		c /= div;
		i++;
	}
	i = (i == 0) ? 1 : i;
	if (!(it = (char *)malloc(i + 1)))
		return (NULL);
	fill_it(it, n, i, type);
	return (it);
}
