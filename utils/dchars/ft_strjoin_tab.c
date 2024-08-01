/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:09:44 by valgrant          #+#    #+#             */
/*   Updated: 2024/08/01 15:31:14 by valgrant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

char	*ft_strjoin_tab(char **tab)
{
	int		i;
	int		len;
	char	*new;
	char	*og;

	if (!tab || !tab[0])
		return (NULL);
	len = 0;
	i = -1;
	while (tab[++i])
		len += ft_strlen(tab[i]);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	og = new;
	i = -1;
	while (tab[++i])
	{
		len = ft_strlen(tab[i]);
		ft_strlcpy(new, tab[i], len);
		new += len;
	}
	*new = '\0';
	return (og);
}
