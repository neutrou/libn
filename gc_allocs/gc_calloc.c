/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:57:44 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:58:30 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdlib.h>

void	*gc_calloc(size_t count, size_t size, t_alloc *mem)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (gc_malloc(1, &mem));
	if (count > 2147483647 || size > 2147483647 || 2147483647 / count < size)
		return (NULL);
	ptr = (void *)gc_malloc(count * size, &mem);
	if (ptr)
		ft_bzero(ptr, size * count);
	return (ptr);
}
