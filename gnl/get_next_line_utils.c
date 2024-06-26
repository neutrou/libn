/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:17:59 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/18 16:25:42 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/gnl.h"

int	ft_tonl(t_list *temp)
{
	int		i;
	t_list	*current;

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

t_list	*ft_getlast(t_list *temp)
{
	t_list	*current;

	current = temp;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	ft_generateline(char **line, t_list *temp)
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

void	ft_freetemp(t_list *temp)
{
	t_list	*current;
	t_list	*next;

	current = temp;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
