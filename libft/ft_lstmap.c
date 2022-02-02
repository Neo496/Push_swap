/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:34:50 by atouba            #+#    #+#             */
/*   Updated: 2022/02/01 14:44:33 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*result;
	t_list	*curr;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	curr = lst;
	result = 0;
	while (lst)
	{
		curr = curr->next;
		tmp = ft_lstnew(f(lst->n));
		ft_lstadd_back(&result, tmp);
		if (!tmp)
		{
			del(lst->n);
			free(lst);
		}
		lst = curr;
	}
	return (result);
}
