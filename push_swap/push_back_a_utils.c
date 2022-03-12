/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_a_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:30:25 by atouba            #+#    #+#             */
/*   Updated: 2022/03/03 15:51:51 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_of_ac(int size_a, int i)
{
	if (i <= size_a / 2)
		return (i);
	else
		return (size_a - i);
}

int	min(int *a, int size_a, int choice)
{
	int	i;
	int	m;
	int	i_m;

	i = 1;
	m = a[0];
	i_m = 0;
	while (i < size_a)
	{
		if (m > a[i])
		{
			m = a[i];
			i_m = i;
		}
		i++;
	}
	if (choice == 0)
		return (m);
	return (i_m);
}

void	init_args(int *i, int *global_m, int *actions, int size_b)
{
	*i = -1;
	*global_m = 0;
	init(actions, size_b, 0);
}

void	assign_gmax_ps(t_data data, int size_a, int size_b, int *global_m)
{
	if (max(data.a, size_a) < max(data.b, size_b))
		*global_m = max(data.b, size_b);
}
