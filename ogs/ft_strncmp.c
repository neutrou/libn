/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:55:23 by valgrant          #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/og.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	ss1;
	unsigned char	ss2;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n > i)
	{
		ss1 = (unsigned char)s1[i];
		ss2 = (unsigned char)s2[i];
		if (ss1 == ss2)
			i++;
		else
			return (ss1 - ss2);
	}
	return (0);
}
