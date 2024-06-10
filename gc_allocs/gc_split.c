/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:50:47 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/10 14:47:16 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdio.h>
#include <stdlib.h>

char	*gc_table(const char *s, char c, int i, t_alloc **mem)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)gc_malloc((ft_strlenword(s, c, i) + 1) * sizeof(char), mem);
	while (s[i] != c && s[i] != 0)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**gc_split(const char *s, char c, t_alloc **mem)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)gc_malloc((ft_wordcount(s, c) + 1) * sizeof(char *), mem);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			str[j] = gc_table(s, c, i, mem);
			i = i + ft_strlenword(s, c, i);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}
