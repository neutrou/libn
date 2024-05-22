/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:21:35 by valgrant          #+#    #+#             */
/*   Updated: 2024/04/01 14:53:41 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libn.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*c;
	int		len;

	len = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	c = malloc((len + 1) * sizeof(char));
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
