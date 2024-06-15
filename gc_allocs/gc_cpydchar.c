/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_cpydchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:00:02 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/15 14:41:22 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"

char	**gc_copydchar(char **og, t_alloc **mem)
{
	int		i;
	int		nrow;
	int		len;
	char	**copy;

	i = -1;
	nrow = 0;
	while (og[nrow])
		nrow++;
	copy = (char **)gc_malloc((nrow + 1) * sizeof(char *), mem);
	while (og[++i])
	{
		len = ft_strlen(og[i]) + 1;
		copy[i] = (char *)gc_malloc((len) * sizeof(char), mem);
		ft_strlcpy(copy[i], og[i], len);
	}
	copy[nrow] = NULL;
	return (copy);
}
