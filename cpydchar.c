/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpydchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:00:02 by valgrant          #+#    #+#             */
/*   Updated: 2024/05/27 19:00:16 by valgrant         ###   ########.fr       */
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
	while (og[nrow] != NULL)
		nrow++;
	copy = (char **)malloc((nrow + 1) * sizeof(char *));
	while (og[++i] != NULL)
	{
		len = strlen(og[i]);
		copy[i] = (char *)malloc((len + 1) * sizeof(char));
		ft_strlcpy(copy[i], og[i], len);
	}
	copy[nrow] = NULL;
	return (copy);
}
