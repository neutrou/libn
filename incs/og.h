/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:43 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/10 11:02:49 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OG_H
# define OG_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libn.h"

int		ft_atoi(const char *nb);
void	ft_bzero(void *s, int len);
void	*ft_calloc(size_t count, size_t size);
int		ft_intlen(int n);
int		ft_hexlen(unsigned long n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_memset(void *s, int c, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *str1, char const *str2);
int		ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *str, char const *sep);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*UTILS*/
size_t	ft_wordcount(const char *s, char c);
int	ft_strlenword(const char *s, char c, int i);
// char	*ft_table(const char *s, char c, int i, t_alloc *mem);

#endif
