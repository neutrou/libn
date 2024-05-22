/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:00:04 by valgrant          #+#    #+#             */
/*   Updated: 2024/03/12 14:48:20 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libn.h"

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	if (size <= 0)
		return (size + ft_strlen((char *)src));
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (size <= i)
		j = j + size;
	else
		j = j + i;
	while (src[++k] && size > i + 1)
	{
		dst[i] = src[k];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
