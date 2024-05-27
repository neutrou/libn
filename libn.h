/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:43 by valgrant          #+#    #+#             */
/*   Updated: 2024/05/22 21:44:43 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBN_H
# define LIBN_H
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_llist
{
	char			*content;
	struct s_llist	*next;
}		t_llist;

char	**copydchar(char** og);
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
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_memset(void *s, int c, int n);
void	ft_puttab(char **tab);
int		ft_printf(const char *format, ...);
int		ft_printfmemlen_fd(unsigned long long ptr, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_putcharlen_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putnbrlen_fd(int n, int fd);
int		ft_putnbruintlen_fd(unsigned int n, int fd);
int		ft_putnbrhexa_fd(unsigned int n, int fd, int maj);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstrlen_fd(char *s, int fd);
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
char	*get_next_line(int fd);
int		ft_tonl(t_llist *temp);
t_llist	*ft_getlast(t_llist *temp);
void	read_and_stock(int fd, t_llist **temp);
void	addtotemp(t_llist **temp, char *buf, int readed);
void	ft_extractline(t_llist *temp, char **tbr);
void	ft_generateline(char **tbr, t_llist *temp);
void	ft_cleantemp(t_llist **temp);
void	ft_freetemp(t_llist *temp);

#endif
