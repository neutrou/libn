/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpydchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:00:02 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/15 14:39:32 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

char	**copydchar(char **og)
{
	int		i;
	int		nrow;
	int		len;
	char	**copy;

	i = -1;
	nrow = 0;
	while (og[nrow])
		nrow++;
	copy = (char **)malloc((nrow + 1) * sizeof(char *));
	while (og[++i])
	{
		len = ft_strlen(og[i]) + 1;
		copy[i] = (char *)malloc((len) * sizeof(char));
		ft_strlcpy(copy[i], og[i], len);
	}
	copy[nrow] = NULL;
	return (copy);
}
