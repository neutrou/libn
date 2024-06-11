/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:28:18 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/11 15:31:49 by valgrant         ###   ########.fr       */
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
