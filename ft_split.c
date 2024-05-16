/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:50:47 by valgrant          #+#    #+#             */
/*   Updated: 2024/03/07 16:00:58 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

char	*ft_table(const char *s, char c, int i)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc((ft_strlenword(s, c, i) + 1) * sizeof(char));
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

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (str);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			str[j] = ft_table(s, c, i);
			i = i + ft_strlenword(s, c, i);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}
