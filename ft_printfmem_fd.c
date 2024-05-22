/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfmem_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:10:01 by valgrant          #+#    #+#             */
/*   Updated: 2024/04/08 18:50:58 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libn.h"

int	ft_putnbrhexalong_fd(unsigned long long n, int fd, int maj)
{
	char	*c;
	int		len;

	if (maj == 1)
		c = "0123456789ABCDEF";
	else
		c = "0123456789abcdef";
	len = ft_hexlen(n);
	if (n >= 16)
	{
		ft_putnbrhexalong_fd(n / 16, fd, maj);
		ft_putnbrhexalong_fd(n % 16, fd, maj);
	}
	else
		write(fd, &c[n], 1);
	return (len);
}

int	ft_printfmemlen_fd(unsigned long long ptr, int fd)
{
	if (ptr == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write(fd, "0x", 2);
	return (ft_putnbrhexalong_fd(ptr, 1, 0) + 2);
}
