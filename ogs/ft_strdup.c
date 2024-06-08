/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:19:24 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*newstr;
	size_t	i;

	i = ft_strlen(str) + 1;
	newstr = (char *)malloc(i * sizeof(char));
	if (newstr == NULL)
		return (newstr);
	ft_strlcpy(newstr, str, i);
	return (newstr);
}
