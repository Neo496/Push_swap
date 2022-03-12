/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:18:58 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:25:00 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_elements(int *a, char **n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		a[i] = ft_atoi(n[i]);
		i++;
	}
}

int	sort_three(int *a, int size_a)
{
	if (size_a == 3 && a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
	{
		rotate(a, 3, 'a');
		return (1);
	}
	if (size_a == 3 && a[0] > a[1])
	{
		swap(a);
		if (a[1] > a[2])
			reverse(a, 3, 'a');
		return (1);
	}
	if (size_a == 3 && a[1] > a[0] && a[1] > a[2])
	{
		reverse(a, 3, 'a');
		if (a[0] > a[1])
			swap(a);
		return (1);
	}
	return (0);
}

int	sort_five(t_data data)
{
	t_topush_data	inf;

	if (data.size_a == 5 && is_sorted(data.a, data.size_a) == 0)
	{
		min_to_top(data.a, data.size_a);
		inf.c = 'b';
		inf.i_from = 0;
		inf.size_from = data.size_a;
		push(data.a, inf, data.b, &data.size_b);
		data.size_a--;
		min_to_top(data.a, data.size_a);
		inf.size_from = 4;
		push(data.a, inf, data.b, &data.size_b);
		data.size_a--;
		sort_three(data.a, 3);
		inf.c = 'a';
		inf.size_from = 2;
		push(data.b, inf, data.a, &data.size_a);
		inf.size_from = 1;
		push(data.b, inf, data.a, &data.size_a);
		return (1);
	}
	return (0);
}

int	is_exit(t_data data)
{
	if (sort_three(data.a, data.size_a) == 1 || sort_five(data) == 1)
	{
		free(data.a);
		free(data.b);
		return (1);
	}
	return (0);
}

int	main(int gv, char **gc)
{
	t_data	data;

	if (gv >= 2 && check(gc + 1, gv -1) == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (gv == 1)
		exit(1);
	data.a = malloc(sizeof(int) * (gv - 1));
	data.b = malloc(sizeof(int) * (gv - 1));
	data.size_a = gv - 1;
	data.size_b = 0;
	set_elements(data.a, gc + 1);
	if (is_exit(data) == 1)
		exit(1);
	lis(data, &(data.size_a), &(data.size_b));
	push_back(data, &(data.size_b), &(data.size_a));
	min_to_top(data.a, data.size_a);
	free(data.a);
	free(data.b);
}

// // system("leaks push_swap");
