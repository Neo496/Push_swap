/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:00:44 by atouba            #+#    #+#             */
/*   Updated: 2022/03/09 16:19:14 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_num(char *c)
{
	int	i;

	i = 0;
	if (c[0] == '-')
		i++;
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(char **s, int to_comp, int top)
{
	int	i;

	i = 0;
	while (i < top)
	{
		if (ft_atoi(s[i]) == to_comp)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *n, char *m)
{
	int	i;

	i = 0;
	while (n[i] == m[i] && n[i] && m[i])
		i++;
	return (n[i] - m[i]);
}

int	check(char **s, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		if (is_num(s[i]) == 0)
			return (0);
		if (ft_atoi(s[i]) == 0 && ft_strcmp(s[i], "0") != 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < size)
	{
		if (is_dup(s, ft_atoi(s[i]), i) == 1)
			return (0);
		i++;
	}
	return (1);
}
