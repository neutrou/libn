/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:50:51 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
		{
			if (needle[j + 1] == 0)
				return ((char *)(haystack + i));
			j++;
			if (haystack[i + j] == 0 || i + j >= len)
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
