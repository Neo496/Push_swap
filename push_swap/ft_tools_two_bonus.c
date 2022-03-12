/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_two_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:09:45 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:10:46 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	execute_inst(char *str, t_data data)
{
	if (!ft_strcmp(str, "sa\n"))
		swap(data.a);
	else if (!ft_strcmp(str, "sb\n"))
		swap(data.b);
	else if (!ft_strcmp(str, "ss\n"))
	{
		swap(data.a);
		swap(data.b);
	}
	else if (!ft_strcmp(str, "ra\n"))
		rotate(data.a, *data.size_a);
	else if (!ft_strcmp(str, "rb\n"))
		rotate(data.b, *data.size_b);
	else if (!ft_strcmp(str, "rr\n"))
	{
		rotate(data.a, *data.size_a);
		rotate(data.b, *data.size_b);
	}
	else if (!ft_strcmp(str, "rra\n"))
		reverse(data.a, *data.size_a);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse(data.b, *data.size_b);
}

void	execute_inst_two(char *str, t_data data, t_topush_data inf)
{
	inf.i_from = 0;
	if (!ft_strcmp(str, "rrr\n"))
	{
		reverse(data.a, *data.size_a);
		reverse(data.b, *data.size_b);
	}
	else if (!ft_strcmp(str, "pa\n"))
	{
		inf.size_from = *data.size_b;
		push_bonus(data.b, inf, data.a, data.size_a);
		*data.size_a += 1;
		*data.size_b -= 1;
	}
	else if (!ft_strcmp(str, "pb\n"))
	{
		inf.size_from = *data.size_a;
		push_bonus(data.a, inf, data.b, data.size_b);
		*data.size_a -= 1;
		*data.size_b += 1;
	}
}
