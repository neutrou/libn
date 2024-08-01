/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:28:18 by valgrant          #+#    #+#             */
/*   Updated: 2024/08/01 15:29:23 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

long	ft_atol(const char *nb)
{
	long	n;
	int		mult;

	n = 0;
	mult = 1;
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '-' || *nb == '+')
		mult = 44 - *nb++;
	while (ft_isdigit(*nb))
		n = (n * 10) + (*nb++ - 48);
	return (n * mult);
}

int	ft_ftoi(float n)
{
	return ((int)roundf(n));
}

float	ft_itof(int n)
{
	return ((float)n);
}
