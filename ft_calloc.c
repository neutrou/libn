/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:57:44 by valgrant          #+#    #+#             */
/*   Updated: 2024/05/15 14:01:59 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libn.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > 2147483647 || size > 2147483647 || 2147483647 / count < size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr)
		ft_bzero(ptr, size * count);
	return (ptr);
}
