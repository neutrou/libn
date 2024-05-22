/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:50:51 by valgrant          #+#    #+#             */
/*   Updated: 2024/02/22 17:50:40 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libn.h"

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
