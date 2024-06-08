/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:48:43 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdlib.h>

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	newstr = (char *)ft_calloc(len + 1, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (len > i)
	{
		newstr[i] = str[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
