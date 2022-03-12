/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:41:03 by atouba            #+#    #+#             */
/*   Updated: 2022/03/04 13:51:09 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_best_e_b_i(t_data data, int size_a, int size_b, t_best_e_vars vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size_b)
	{
		vars.actions[i] = num_of_ac(size_b, i);
		j = -1;
		if (data.b[i] == vars.global_m)
			vars.actions[i] += num_of_ac(size_a, min(data.a, size_a, 1));
		else
		{
			while (++j < size_a - 1)
			{
				if (data.b[i] > data.a[j] && data.b[i] < data.a[j + 1])
				{
					vars.actions[i] += num_of_ac(size_a, j + 1);
					break ;
				}
			}
		}
	}
}

int	best_elem_b_i(t_data data, int size_b, int size_a, int *elem_to_push)
{
	t_best_e_vars	vars;
	int				i;
	int				m_actions;

	vars.actions = malloc(sizeof(int) * size_b);
	init_args(&i, &(vars.global_m), vars.actions, size_b);
	if (data.b[0] < data.a[0] && data.b[0] > data.a[size_a - 1])
	{
		*elem_to_push = data.b[0];
		free(vars.actions);
		return (0);
	}
	assign_gmax_ps(data, size_a, size_b, &(vars.global_m));
	norm_best_e_b_i(data, size_a, size_b, vars);
	m_actions = min(vars.actions, size_b, 1);
	free(vars.actions);
	*elem_to_push = data.b[m_actions];
	return (m_actions);
}

int	elem_aft(int *a, int size_a, int n)
{
	int	i;

	i = 0;
	if (n > a[size_a - 1] && n < a[0])
		return (0);
	while (i < size_a - 1)
	{
		if (n > a[i] && n < a[i + 1])
			return (i + 1);
		i++;
	}
	return (min(a, size_a, 1));
}

void	push_back(t_data data, int *l_b, int *l_a)
{
	int				elem_push_to_a;
	int				i_elem_push_to_a;
	int				n_elem_aft;
	t_topush_data	inf_b;

	inf_b.c = 'a';
	while (data.size_b > 0)
	{		
		i_elem_push_to_a = best_elem_b_i(data, *l_b, *l_a, &elem_push_to_a);
		n_elem_aft = elem_aft(data.a, data.size_a, elem_push_to_a);
		rot_or_rev(data.a, n_elem_aft, data.size_a, 'a');
		inf_b.i_from = i_elem_push_to_a;
		inf_b.size_from = data.size_b;
		push(data.b, inf_b, data.a, &(data.size_a));
		data.size_b--;
		(*l_b)--;
		(*l_a)++;
	}
}
