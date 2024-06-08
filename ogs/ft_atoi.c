/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:27:25 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *nb)
{
	int	integer;
	int	mult;

	integer = 0;
	mult = 1;
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '-' || *nb == '+')
		mult = 44 - *nb++;
	while (ft_isdigit(*nb))
		integer = (integer * 10) + (*nb++ - 48);
	return (integer * mult);
}
