/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpydchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:00:02 by valgrant          #+#    #+#             */
/*   Updated: 2024/05/28 15:55:47 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libn.h"

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
		len = ft_strlen(og[i]);
		copy[i] = (char *)malloc((len + 1) * sizeof(char));
		ft_strlcpy(copy[i], og[i], len + 1);
	}
	copy[nrow] = NULL;
	return (copy);
}
