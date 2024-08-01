/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:48:43 by valgrant          #+#    #+#             */
/*   Updated: 2024/07/26 15:10:42 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdlib.h>

char	*gc_substr(char const *str, unsigned int start, size_t len, t_alloc **mem)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str))
		return (gc_malloc(1 * sizeof(char), mem));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	newstr = gc_malloc((len + 1) *sizeof(char), mem);
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
