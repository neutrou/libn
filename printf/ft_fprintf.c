/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:06:31 by valgrant          #+#    #+#             */
/*   Updated: 2024/07/22 16:19:46 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"
#include <stdarg.h>

int	ft_fprintf(int fd, const char *format, ...)
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
				ft_putchar_fd(format[i++], fd);
			}
			else
				len += get_type(format[i++], args, fd) - 2;
		}
		else
			write(1, &format[i++], fd);
	}
	va_end(args);
	return (len + i);
}
