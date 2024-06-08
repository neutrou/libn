/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:21:35 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 18:18:05 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdlib.h>
#include <stdio.h>

char	*gc_itoa(int n, t_alloc *mem)
{
	char	*c;
	int		len;

	len = ft_intlen(n);
	if (n == -2147483648)
		return (gc_strdup("-2147483648", mem));
	if (n == 0)
		return (gc_strdup("0", mem));
	c = gc_malloc((len + 1) * sizeof(char), &mem);
	if (c == NULL)
		return (NULL);
	c[len--] = 0;
	if (n < 0)
	{
		c[0] = 45;
		n = n * -1;
	}
	while (n > 0)
	{
		c[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (c);
}
