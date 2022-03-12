/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:37 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:00:17 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a)
{
	int	s;

	if (a)
	{
		s = a[0];
		a[0] = a[1];
		a[1] = s;
	}
	write(1, "sa\n", 3);
}

void	write_push(char c)
{
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push(int *b, t_topush_data inf, int *a, int *size_a)
{
	int	i;
	int	l;

	i = 0;
	if (inf.c)
	{
		if (inf.c == 'b')
			rot_or_rev(b, inf.i_from, inf.size_from, 'a');
		else
			rot_or_rev(b, inf.i_from, inf.size_from, 'b');
	}
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
	(*size_a)++;
	write_push(inf.c);
}

void	rotate(int *a, int size, char c)
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
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse(int	*a, int size, char c)
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
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
