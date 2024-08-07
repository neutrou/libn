/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:35 by neutrou           #+#    #+#             */
/*   Updated: 2024/07/22 16:21:44 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_fprintf(int fd, const char *format, ...);
int	ft_printf(const char *format, ...);
int	ft_printfmemlen_fd(unsigned long long ptr, int fd);
int	ft_putcharlen_fd(char c, int fd);
int	ft_putnbrlen_fd(int n, int fd);
int	ft_putnbruintlen_fd(unsigned int n, int fd);
int	ft_putnbrhexa_fd(unsigned int n, int fd, int maj);
int	ft_putstrlen_fd(char *s, int fd);
int	get_type(char c, va_list args, int fd);

#endif