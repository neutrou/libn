/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:24 by neutrou           #+#    #+#             */
/*   Updated: 2024/06/18 16:28:34 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# include "libn.h"

//GC GNL
char	*gc_get_next_line(int fd, t_alloc *mem);
int		gc_tonl(t_list *temp);
t_list	*gc_getlast(t_list *temp);
void	gc_read_and_stock(int fd, t_list **temp, t_alloc *mem);
void	gc_addtotemp(t_list **temp, char *buf, int readed, t_alloc *mem);
void	gc_extractline(t_list *temp, char **tbr, t_alloc *mem);
void	gc_generateline(char **line, t_list *temp, t_alloc *mem);
void	gc_cleantemp(t_list **temp, t_alloc *mem);
void	gc_freetemp(t_list *temp, t_alloc *mem);

//CLASSIC GNL
char	*get_next_line(int fd);
int		ft_tonl(t_list *temp);
t_list	*ft_getlast(t_list *temp);
void	read_and_stock(int fd, t_list **temp);
void	addtotemp(t_list **temp, char *buf, int readed);
void	ft_extractline(t_list *temp, char **tbr);
void	ft_generateline(char **tbr, t_list *temp);
void	ft_cleantemp(t_list **temp);
void	ft_freetemp(t_list *temp);

#endif