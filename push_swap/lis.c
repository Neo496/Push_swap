/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:45:57 by atouba            #+#    #+#             */
/*   Updated: 2022/03/03 15:47:16 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_l_func(int *a, int size_a, int *i, int *y)
{
	*i = -1;
	min_to_top(a, size_a);
	init(y, size_a, -1);
}

int	lenght(t_data data, int *y, int *last_elem_ind)
{
	t_mini_data	it;
	int			*x;
	int			max_i;

	x = malloc(sizeof(int) * (data.size_a));
	init_l_func(data.a, data.size_a, &(it.i), y);
	init(x, data.size_a, 1);
	x[0] = 0;
	while (++(it.i) < data.size_a)
	{
		it.j = -1;
		while (++(it.j) < it.i)
		{
			if (data.a[it.j] < data.a[it.i] && data.a[it.j] < data.a[it.i])
			{
					x[it.i] = x[it.j] + 1;
					y[it.i] = it.j;
			}
		}
	}
	max_i = max_elem(x, last_elem_ind, data);
	free(x);
	return (max_i);
}

void	free_and_init_lis(int *y, int *is, int *l_a, int l_is)
{
	free(y);
	free(is);
	*l_a = l_is;
}

void	lis(t_data data, int *l_a, int *l_b)
{
	int	j;
	int	last_elem_ind;
	int	*y;
	int	l_is;
	int	*is;

	y = malloc(sizeof(int) * (data.size_a));
	j = lenght(data, y, &last_elem_ind);
	l_is = j;
	is = malloc(sizeof(int) * j);
	is[0] = data.a[0];
	*l_b = data.size_a - j;
	is[j - 1] = data.a[last_elem_ind];
	last_elem_ind = y[last_elem_ind];
	j -= 1;
	while (j-- > 0)
	{
		is[j] = data.a[last_elem_ind];
		last_elem_ind = y[last_elem_ind];
	}
	is[0] = data.a[0];
	copy_array(is, l_is, data);
	free_and_init_lis(y, is, l_a, l_is);
}
