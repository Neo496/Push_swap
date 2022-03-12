/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:37:22 by atouba            #+#    #+#             */
/*   Updated: 2022/03/03 15:43:51 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_or_rev(int *a, int ind, int size, char c)
{
	if (ind == 0)
		return ;
	if (ind <= size / 2)
	{
		while (ind > 0)
		{
			rotate(a, size, c);
			ind--;
		}
	}
	else
	{
		while (size - ind > 0)
		{
			reverse(a, size, c);
			ind++;
		}
	}
}

void	min_to_top(int *a, int size)
{
	int	i_min;

	i_min = ind_min(a, size);
	rot_or_rev(a, i_min, size, 'a');
}

int	max_elem(int *x, int *last_element, t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = x[0];
	while (i < data.size_a)
	{
		if (j < x[i])
		{
			j = x[i];
			*last_element = i;
		}
		i++;
	}
	j++;
	return (j);
}

void	init(int *a, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		a[i] = n;
		i++;
	}
}
