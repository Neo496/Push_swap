/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:35:58 by atouba            #+#    #+#             */
/*   Updated: 2022/03/03 15:55:08 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int *a, int size_a)
{
	int	i;
	int	m;

	i = 1;
	m = a[0];
	while (i < size_a)
	{
		if (m < a[i])
			m = a[i];
		i++;
	}
	return (m);
}

void	init_n_o_t_b(int *i, int *j, int *l, int *i_pushed)
{
	*i = -1;
	*j = 0;
	*l = 1;
	*i_pushed = 0;
}

void	not_orga_to_b(t_data data, int *lis, int size_lis)
{
	int				i;
	int				j;
	int				l;
	int				i_pushed;
	t_topush_data	inf;

	init_n_o_t_b(&i, &j, &l, &i_pushed);
	inf.c = 'b';
	while (++i < data.size_a && i_pushed < data.size_a - size_lis)
	{
		if (data.a[i] == lis[j] && j < size_lis)
				j++;
		else
		{
			inf.i_from = i;
			inf.size_from = data.size_a;
			push(data.a, inf, data.b, &data.size_b);
			i_pushed++;
			i = -1;
			l++;
		}
	}
	data.size_b = data.size_a - size_lis;
}

void	copy_array(int *source, int l_s, t_data data)
{
	int	i;

	i = 1;
	not_orga_to_b(data, source, l_s);
	while (i < l_s)
	{
		data.a[i] = source[i];
		i++;
	}
	while (i < data.size_a)
	{
		data.a[i] = 0;
		i++;
	}
}

int	ind_min(int *a, int size)
{
	int	i;
	int	min;
	int	i_min;

	i = 1;
	min = a[0];
	i_min = 0;
	while (i < size)
	{
		if (min > a[i])
		{
			min = a[i];
			i_min = i;
		}
		i++;
	}
	return (i_min);
}
