/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:00:04 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"

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
