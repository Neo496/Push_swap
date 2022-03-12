/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:32:12 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:19:13 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_data	main_pushswap(int gv, char **gc)
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
	set_elements(data.a, gc + 1);
	return (data);
}

void	ftt_free(char *str, int *a, int *b)
{
	free(str);
	free(a);
	free(b);
}

void	free_and_exit(char *str, int *a, int *b)
{
	ftt_free(str, a, b);
	write(1, "Error\n", 6);
	exit(1);
}

void	write_verdict(int *a, int size_a, int size_b)
{
	if (is_sorted(a, size_a) && size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int gv, char **gc)
{
	char			*str;
	t_data			data;
	t_topush_data	inf;
	int				x;
	int				n;

	inf.i_from = 0;
	data = main_pushswap(gv, gc);
	x = gv - 1;
	data.size_a = &x;
	n = 0;
	data.size_b = &n;
	str = get_next_line(n);
	while (str)
	{
		if (check_inst(str) == 0)
			free_and_exit(str, data.a, data.b);
		execute_inst(str, data);
		execute_inst_two(str, data, inf);
		free(str);
		str = get_next_line(0);
	}
	write_verdict(data.a, *data.size_a, *data.size_b);
	ftt_free(str, data.a, data.b);
}
