/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:24 by neutrou           #+#    #+#             */
/*   Updated: 2024/06/08 18:14:35 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# include "libn.h"

char	*get_next_line(int fd, t_alloc *mem);
int		ft_tonl(t_list *temp);
t_list	*ft_getlast(t_list *temp);
void	read_and_stock(int fd, t_list **temp, t_alloc *mem);
void	addtotemp(t_list **temp, char *buf, int readed, t_alloc *mem);
void	ft_extractline(t_list *temp, char **tbr, t_alloc *mem);
void	ft_generateline(char **line, t_list *temp, t_alloc *mem);
void	ft_cleantemp(t_list **temp, t_alloc *mem);
void	ft_freetemp(t_list *temp);

#endif