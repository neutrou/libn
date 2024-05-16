/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:17:59 by valgrant          #+#    #+#             */
/*   Updated: 2024/04/09 19:52:39 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* trouve le nl */

int	ft_tonl(t_llist *temp)
{
	int		i;
	t_llist	*current;

	if (temp == NULL)
		return (0);
	current = ft_getlast(temp);
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

t_llist	*ft_getlast(t_llist *temp)
{
	t_llist	*current;

	current = temp;
	while (current && current->next)
		current = current->next;
	return (current);
}

/* compte les chars et malloc */

void	ft_generateline(char **line, t_llist *temp)
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
	*line = malloc(sizeof(char) * (len + 1));
}

/* free temp*/

void	ft_freetemp(t_llist *temp)
{
	t_llist	*current;
	t_llist	*next;

	current = temp;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
