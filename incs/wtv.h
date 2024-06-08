/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:51 by neutrou           #+#    #+#             */
/*   Updated: 2024/06/08 18:17:10 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WTV_H
# define WTV_H
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# include "libn.h"

//DCHARS MANIP
char	**copydchar(char **og, t_alloc *mem);
void	freedchar(char	**tab);
void	ft_puttab(char **tab);

//GC MALLOC
void	gc_free(void *ptr, t_alloc **mem);
void	gc_free_all(t_alloc **mem);
void	*gc_malloc(int size, t_alloc **mem);
void	insert_alloc(void *ptr, t_alloc **mem);

//GC FUNCTIONS
char	*gc_itoa(int n, t_alloc *mem);
char	*gc_strdup(const char *str, t_alloc *mem);
char	**gc_split(const char *s, char c, t_alloc *mem);
void	*gc_calloc(size_t count, size_t size, t_alloc *mem);
char	*gc_strjoin(char const *str1, char const *str2, t_alloc *mem);

#endif