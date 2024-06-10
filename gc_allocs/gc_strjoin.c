/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:42:37 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/10 14:47:29 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"

char	*gc_strjoin(char const *str1, char const *str2, t_alloc **mem)
{
	char	*fstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fstr = gc_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char), mem);
	while (str1[i] != '\0')
	{
		fstr[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		fstr[i + j] = str2[j];
		j++;
	}
	fstr[i + j] = '\0';
	return (fstr);
}
