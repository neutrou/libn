/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:17:58 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 18:20:52 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/gnl.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd, t_alloc *mem)
{
	static t_list	*temp[1024];
	char			*tbr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tbr = NULL;
	read_and_stock(fd, &temp[fd], mem);
	if (temp[fd] == NULL)
		return (NULL);
	ft_extractline(temp[fd], &tbr, mem);
	ft_cleantemp(&temp[fd], mem);
	if (tbr[0] == '\0')
	{
		ft_freetemp(temp[fd]);
		temp[fd] = NULL;
		gc_free(tbr, &mem);
		return (NULL);
	}
	return (tbr);
}

/* read() et stock dans temp */

void	read_and_stock(int fd, t_list **temp, t_alloc *mem)
{
	char	*buffer;
	int		len;

	len = 1;
	while (!ft_tonl(*temp) && len != 0)
	{
		buffer = gc_malloc(sizeof(char) * (BUFFER_SIZE + 1), &mem);
		if (buffer == NULL)
			return ;
		len = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*temp == NULL && len == 0) || len == -1)
		{
			gc_free(buffer, &mem);
			return ;
		}
		buffer[len] = '\0';
		addtotemp(temp, buffer, len, mem);
		gc_free(buffer, &mem);
	}
}

/* cat le buffer et le temp */

void	addtotemp(t_list **stash, char *buffer, int len, t_alloc *mem)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = gc_malloc(sizeof(t_list), &mem);
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = gc_malloc(sizeof(char) * (len + 1), &mem);
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

void	ft_extractline(t_list *temp, char **tbr, t_alloc *mem)
{
	int	i;
	int	j;

	if (temp == NULL)
		return ;
	ft_generateline(tbr, temp, mem);
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

void	ft_cleantemp(t_list **temp, t_alloc *mem)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = gc_malloc(sizeof(t_list), &mem);
	if (temp == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_getlast(*temp);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = gc_malloc(sizeof(char) * \
	((ft_strlen(last->content) - i) + 1), &mem);
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	ft_freetemp(*temp);
	*temp = clean_node;
}
