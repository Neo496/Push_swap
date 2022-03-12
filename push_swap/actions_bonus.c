/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:37 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:16:14 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(int *a)
{
	int	s;

	s = a[0];
	a[0] = a[1];
	a[1] = s;
}

void	push_bonus(int *b, t_topush_data inf, int *a, int *size_a)
{
	int	i;
	int	l;

	i = 0;
	l = *size_a;
	while (l--)
		a[l + 1] = a[l];
	a[0] = b[0];
	i = 0;
	while (i < inf.size_from - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
}

void	rotate(int *a, int size)
{
	int	save;
	int	i;

	i = 0;
	save = a[0];
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = save;
}

void	reverse(int	*a, int size)
{
	int	i;
	int	save;

	i = 0;
	save = a[size - 1];
	size--;
	while (size > 0)
	{
		a[size] = a[size - 1];
		size--;
	}
	a[0] = save;
}
