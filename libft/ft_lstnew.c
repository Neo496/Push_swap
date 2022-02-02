/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:38:40 by atouba            #+#    #+#             */
/*   Updated: 2022/02/01 14:37:52 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int n)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->n = n;
	new_list->next = 0;
	return (new_list);
}
// int main()
// {
// 	char s[] = "hello world";
// 	t_list *root;
// 	root = ft_lstnew((void *)s);
// 	printf("%s", (char *)root->content);
// }