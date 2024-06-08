/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:35 by neutrou           #+#    #+#             */
/*   Updated: 2024/06/08 15:43:28 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printfmemlen_fd(unsigned long long ptr, int fd);
int		ft_putcharlen_fd(char c, int fd);
int		ft_putnbrlen_fd(int n, int fd);
int		ft_putnbruintlen_fd(unsigned int n, int fd);
int		ft_putnbrhexa_fd(unsigned int n, int fd, int maj);
int		ft_putstrlen_fd(char *s, int fd);

#endif