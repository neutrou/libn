/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:06:31 by valgrant          #+#    #+#             */
/*   Updated: 2024/07/22 16:19:14 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdarg.h>

int	get_type(char c, va_list args, int fd)
{
	int	len;

	len = 0;
	if (c == 'c')
	{
		len = 1;
		ft_putchar_fd(va_arg(args, int), fd);
	}
	else if (c == 's')
		len = ft_putstrlen_fd(va_arg(args, char *), fd);
	else if (c == 'p')
		len = ft_printfmemlen_fd(va_arg(args, unsigned long long), fd);
	else if (c == 'i' || c == 'd')
		len = ft_putnbrlen_fd(va_arg(args, int), fd);
	else if (c == 'u')
		len = ft_putnbruintlen_fd(va_arg(args, unsigned int), fd);
	else if (c == 'x')
		len = ft_putnbrhexa_fd(va_arg(args, unsigned int), fd, 0);
	else if (c == 'X')
		len = ft_putnbrhexa_fd(va_arg(args, unsigned int), fd, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
			{
				len--;
				ft_putchar_fd(format[i++], 1);
			}
			else
				len += get_type(format[i++], args, 1) - 2;
		}
		else
			write(1, &format[i++], 1);
	}
	va_end(args);
	return (len + i);
}
