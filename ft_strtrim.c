/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:48:20 by valgrant          #+#    #+#             */
/*   Updated: 2024/03/05 18:27:46 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_issep(char c, char const *sep)
{
	int	i;

	i = ft_strlen(sep);
	while (i >= 0)
	{
		if (sep[i] == c)
			return (1);
		i--;
	}
	return (0);
}

size_t	ft_firstcheck(char const *str, char const *sep)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_issep(str[i], sep) == 0)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

size_t	ft_lastcheck(char const *str, char const *sep)
{
	size_t	i;

	i = ft_strlen(str);
	while (i != 0)
	{
		if (ft_issep(str[i], sep) == 0)
		{
			return (ft_strlen(str) - i - 1);
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *str, char const *sep)
{
	char		*newstr;
	size_t		i;
	size_t		j;
	size_t		k;

	i = ft_firstcheck(str, sep);
	j = 0;
	k = ft_lastcheck(str, sep);
	newstr = (char *)ft_calloc(ft_strlen(str) - i - k + 1, sizeof(char));
	if (newstr == NULL)
		return (newstr);
	while (i < ft_strlen(str) - k)
	{
		newstr[j] = str[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
