/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:19:24 by valgrant          #+#    #+#             */
/*   Updated: 2024/02/23 11:44:01 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
