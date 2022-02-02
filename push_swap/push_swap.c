/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:18:58 by atouba            #+#    #+#             */
/*   Updated: 2022/02/02 11:53:29 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
// #include "libft/libft/libft.h"
#include "push_swap.h"

void	display(t_list	*root)
{
	if (!root)
		return ;
	t_list	*curr = root;
	while (curr)
	{
		printf("%d ", (int)curr->n);
		curr = curr->next;
	}
}

int main(int gv, char **gc)
{
	int i = 1;

	t_list	*a = 0;
	t_list	*b = 0;
	b = ft_lstnew(2);
	b->next = ft_lstnew(5);
	while (gc[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(gc[i])));
		i++;
	}
	printf("a :");
	display(a);
	printf("\n");
	a = reverse_r(&a);
	printf("a :");
	display(a);
	
	// printf("\n");
	// printf("b :");
	// display(b);
	// free(b);
	// b = b->next;
	// display(b);
	// while (gc[i])
	// {
	// 	printf("%s\n", gc[i]);
	// 	i++;
	// }
}