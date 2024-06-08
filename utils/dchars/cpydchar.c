/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpydchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:00:02 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 21:40:47 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

char	**copydchar(char **og, t_alloc *mem)
{
	int		i;
	int		nrow;
	int		len;
	char	**copy;

	i = -1;
	nrow = 0;
	while (og[nrow])
		nrow++;
	copy = (char **)gc_malloc((nrow + 1) * sizeof(char *), &mem);
	while (og[++i])
	{
		len = ft_strlen(og[i]) + 1;
		copy[i] = (char *)gc_malloc((len) * sizeof(char), &mem);
		ft_strlcpy(copy[i], og[i], len);
	}
	copy[nrow] = NULL;
	return (copy);
}
