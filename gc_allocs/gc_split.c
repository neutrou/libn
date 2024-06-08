/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:50:47 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 16:00:06 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

int	ft_strlenword(const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i] != 0)
	{
		j++;
		i++;
	}
	return (j);
}

char	*ft_table(const char *s, char c, int i, t_alloc *mem)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)gc_malloc((ft_strlenword(s, c, i) + 1) * sizeof(char), &mem);
	if (str == NULL)
		return (str);
	while (s[i] != c && s[i] != 0)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**gc_split(const char *s, char c, t_alloc *mem)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)gc_malloc((ft_wordcount(s, c) + 1) * sizeof(char *), &mem);
	if (str == NULL)
		return (str);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			str[j] = ft_table(s, c, i, mem);
			i = i + ft_strlenword(s, c, i);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}
