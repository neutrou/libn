/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:17:58 by valgrant          #+#    #+#             */
/*   Updated: 2024/05/22 21:42:31 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libn.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_llist	*temp[1024];
	char			*tbr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tbr = NULL;
	read_and_stock(fd, &temp[fd]);
	if (temp == NULL)
		return (NULL);
	ft_extractline(temp[fd], &tbr);
	ft_cleantemp(&temp[fd]);
	if (tbr[0] == '\0')
	{
		ft_freetemp(temp[fd]);
		temp[fd] = NULL;
		free(tbr);
		return (NULL);
	}
	return (tbr);
}

/* read() et stock dans temp */

void	read_and_stock(int fd, t_llist **temp)
{
	char	*buffer;
	int		len;

	len = 1;
	while (!ft_tonl(*temp) && len != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		len = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*temp == NULL && len == 0) || len == -1)
		{
			free(buffer);
			return ;
		}
		buffer[len] = '\0';
		addtotemp(temp, buffer, len);
		free(buffer);
	}
}

/* cat le buffer et le temp */

void	addtotemp(t_llist **stash, char *buffer, int len)
{
	int		i;
	t_llist	*last;
	t_llist	*new_node;

	new_node = malloc(sizeof(t_llist));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (len + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < len)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_getlast(*stash);
	last->next = new_node;
}

/* prends les char et les mets jusqu'au nl */

void	ft_extractline(t_llist *temp, char **tbr)
{
	int	i;
	int	j;

	if (temp == NULL)
		return ;
	ft_generateline(tbr, temp);
	if (*tbr == NULL)
		return ;
	j = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				(*tbr)[j++] = temp->content[i];
				break ;
			}
			(*tbr)[j++] = temp->content[i++];
		}
		temp = temp->next;
	}
	(*tbr)[j] = '\0';
}

/* nettoie le temp et garde les char non returned */

void	ft_cleantemp(t_llist **temp)
{
	t_llist	*last;
	t_llist	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_llist));
	if (temp == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_getlast(*temp);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * \
	((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	ft_freetemp(*temp);
	*temp = clean_node;
}
