/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:33:39 by atouba            #+#    #+#             */
/*   Updated: 2022/02/01 14:42:32 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int)) //change
{
	t_list	*curr;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		curr = (*lst)->next;
		del((*lst)->n);
		free((*lst));
		*lst = curr;
	}
	lst = 0;
}
