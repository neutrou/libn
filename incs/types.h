/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:13:35 by neutrou           #+#    #+#             */
/*   Updated: 2024/06/08 18:14:11 by neutrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_alloc
{
	void			*adress;
	struct s_alloc	*next;
}				t_alloc;

#endif