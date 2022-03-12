/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_one_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:08:46 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:15:15 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	rot_or_rev(int *a, int ind, int size)
{
	if (ind == 0)
		return ;
	if (ind <= size / 2)
	{
		while (ind > 0)
		{
			rotate(a, size);
			ind--;
		}
	}
	else
	{
		while (size - ind > 0)
		{
			reverse(a, size);
			ind++;
		}
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

void	min_to_top(int *a, int size)
{
	int	i_min;

	i_min = ind_min(a, size);
	rot_or_rev(a, i_min, size);
}

int	check_inst(char *str)
{
	if (ft_strcmp(str, "ra\n") && ft_strcmp(str, "rb\n") && ft_strcmp(str, "rra\n")
		&& ft_strcmp(str, "rrb\n") && ft_strcmp(str, "rr\n")
		&& ft_strcmp(str, "rrr\n") && ft_strcmp(str, "sa\n")
		&& ft_strcmp(str, "sb\n") && ft_strcmp(str, "ss\n")
		&& ft_strcmp(str, "pa\n") && ft_strcmp(str, "pb\n"))
		return (0);
	return (1);
}
