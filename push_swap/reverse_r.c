/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:19:54 by atouba            #+#    #+#             */
/*   Updated: 2022/02/02 22:39:13 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function doesn't work as expected
t_list	*reverse_r(t_list **root)
{
	t_list	*curr;
	int		p, n;
	t_list	*save;
	t_list	*last;

	save = *root;
	n = save->n;
	while (save)
	{
		// printf(" x ");
		p = n;
		if (!save)
			break ;
		save = save->next;
		n = save->n;
		save->n = p;
	}
	save = *root;
	save->n = n;
	return (save);
}
