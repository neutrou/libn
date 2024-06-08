/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:19:24 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 16:04:07 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdlib.h>

char	*gc_strdup(const char *str, t_alloc *mem)
{
	char	*newstr;
	size_t	i;

	i = ft_strlen(str) + 1;
	newstr = (char *)gc_malloc(i * sizeof(char), &mem);
	if (newstr == NULL)
		return (newstr);
	ft_strlcpy(newstr, str, i);
	return (newstr);
}
