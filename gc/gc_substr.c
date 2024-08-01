/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:48:43 by valgrant          #+#    #+#             */
/*   Updated: 2024/08/01 15:37:14 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdlib.h>

char	*gc_substr(char const *s, unsigned int sp, size_t len, t_alloc **mem)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (sp > ft_strlen(s))
		return (gc_malloc(1 * sizeof(char), mem));
	if (ft_strlen(s + sp) < len)
		len = ft_strlen(s + sp);
	newstr = gc_malloc((len + 1) * sizeof(char), mem);
	if (newstr == NULL)
		return (NULL);
	while (len > i)
	{
		newstr[i] = s[sp + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
