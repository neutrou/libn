/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:23:56 by neutrou           #+#    #+#             */
/*   Updated: 2024/07/17 13:16:33 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../incs/utils.h"

void	ft_puttab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		write(1, "\n", 1);
	}
}
