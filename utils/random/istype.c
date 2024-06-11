/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istype.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:29:37 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/11 15:31:32 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

bool	isint(char *n)
{
	int		nbr;
	long	nbr2;
	size_t	i;
	size_t	j;

	i = 0;
	while (n[i] == '+' || n[i] == '-')
		i++;
	j = i;
	while (ft_isdigit(n[j]))
		j++;
	if (j != ft_strlen(n) || i == j)
		return (0);
	nbr = ft_atoi(n);
	nbr2 = ft_atol(n);
	n += i;
	if (nbr == nbr2)
	{
		if (nbr >= 0 && ft_strlen(n) == (size_t)ft_intlen(nbr))
			return (1);
		if (nbr < 0 && ft_strlen(n) + 1 == (size_t)ft_intlen(nbr))
			return (1);
	}
	return (0);
}
