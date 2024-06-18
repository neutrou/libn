/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:17:59 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/18 16:28:09 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/gnl.h"

/* trouve le nl */

int	gc_tonl(t_list *temp)
{
	int		i;
	t_list	*current;

	if (temp == NULL)
		return (0);
	current = gc_getlast(temp);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* donne un pointeur sur le dernier element de la list*/

t_list	*gc_getlast(t_list *temp)
{
	t_list	*current;

	current = temp;
	while (current && current->next)
		current = current->next;
	return (current);
}

/* compte les chars et gc_malloc */

void	gc_generateline(char **line, t_list *temp, t_alloc *mem)
{
	int	i;
	int	len;

	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		temp = temp->next;
	}
	*line = gc_malloc(sizeof(char) * (len + 1), &mem);
}

/* gc_free temp*/

void	gc_freetemp(t_list *temp, t_alloc *mem)
{
	t_list	*current;
	t_list	*next;

	current = temp;
	while (current)
	{
		gc_free(current->content, &mem);
		next = current->next;
		gc_free(current, &mem);
		current = next;
	}
}
