/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:51 by neutrou           #+#    #+#             */
/*   Updated: 2024/06/15 14:39:56 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# ifndef COLORS
#  define COLORS
#  define RED		"\x1b[31m"
#  define GREEN		"\x1b[32m"
#  define YELLOW	"\x1b[33m"
#  define BLUE		"\x1b[34m"
#  define MAGENTA	"\x1b[35m"
#  define CYAN		"\x1b[36m"
#  define BROWN		"\x1b[33m"
#  define GREY		"\x1b[90m"
#  define RESET		"\x1b[0m"
# endif
# include "libn.h"

//DCHARS MANIP
char	**copydchar(char **og);
void	freedchar(char	**tab);
void	ft_puttab(char **tab);

//GC MALLOC
void	gc_free(void *ptr, t_alloc **mem);
void	gc_free_all(t_alloc **mem);
void	*gc_malloc(int size, t_alloc **mem);
void	insert_alloc(void *ptr, t_alloc **mem);

//GC FUNCTIONS
char	*gc_itoa(int n, t_alloc **mem);
char	*gc_strdup(const char *str, t_alloc **mem);
char	**gc_split(const char *s, char c, t_alloc **mem);
void	*gc_calloc(size_t count, size_t size, t_alloc **mem);
char	*gc_strjoin(char const *str1, char const *str2, t_alloc **mem);
char	**gc_copydchar(char **og, t_alloc **mem);

//IDK EVEN KNOW
long	ft_atol(const char *nb);
bool	isint(char *n);

#endif