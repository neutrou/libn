/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:07:54 by ewoillar          #+#    #+#             */
/*   Updated: 2024/06/08 21:40:47 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/utils.h"

void	gc_free(void *adress, t_alloc **mem)
{
	t_alloc	*cpy;
	t_alloc	*temp;

	if (!*mem)
		return ;
	cpy = *mem;
	while (cpy)
	{
		if (cpy->adress == adress)
		{
			temp = cpy;
			if (cpy->next)
				cpy = cpy->next;
			if ((*mem)->adress == temp->adress)
				*mem = cpy;
			free(temp->adress);
			free(temp);
			return ;
		}
		cpy = cpy->next;
	}
}

void	gc_free_all(t_alloc **mem)
{
	while ((*mem)->next != NULL)
		gc_free((*mem)->adress, mem);
	gc_free((*mem)->adress, mem);
}

void	insert_alloc(void *ptr, t_alloc **mem)
{
	t_alloc	*new;

	new = malloc(sizeof(t_alloc));
	new->adress = ptr;
	new->next = NULL;
	if (mem && *mem)
		new->next = *mem;
	*mem = new;
}

void	*gc_malloc(int size, t_alloc **mem)
{
	void	*ptr;

	ptr = malloc(size);
    if (!ptr)
    {
        gc_free_all(mem);
        ft_putstr_fd(RED, 2);
        ft_putstr_fd("Critical : malloc failure\n", 2);
        ft_putstr_fd(RESET, 2);
        exit(1);
    }
	insert_alloc(ptr, mem);
	return (ptr);
}
