/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:27:04 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"

int	ft_putnbrhexa_fd(unsigned int n, int fd, int maj)
{
	char	*c;
	int		len;

	if (maj == 1)
		c = "0123456789ABCDEF";
	else
		c = "0123456789abcdef";
	len = ft_hexlen((unsigned long)n);
	if (n >= 16)
	{
		ft_putnbrhexa_fd(n / 16, fd, maj);
		ft_putnbrhexa_fd(n % 16, fd, maj);
	}
	else
		write(fd, &c[n], 1);
	return (len);
}
