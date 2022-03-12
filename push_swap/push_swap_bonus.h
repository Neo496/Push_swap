/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:32:37 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:21:53 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct data
{
	int	*a;
	int	*b;
	int	*size_a;
	int	*size_b;
}	t_data;

typedef struct topush_data
{
	int		i_from;
	int		size_from;
}	t_topush_data;

typedef struct mini_data
{
	int	i;
	int	j;
}	t_mini_data;

typedef struct best_e_vars
{
	int	*actions;
	int	global_m;
}	t_best_e_vars;

void	swap(int *a);
void	push_bonus(int *b, t_topush_data inf, int *a, int *size_a);
void	rotate(int *a, int size);
void	reverse(int	*a, int size);
void	min_to_top(int *a, int size);
void	rot_or_rev(int *a, int ind, int size);
int		is_dup(char **s, int to_comp, int top);
int		is_num(char *c);
int		check(char **s, int size);
int		max(int *a, int size_a);
int		min(int *a, int size_a, int choice);
int		ft_atoi(const char *str);
int		ind_min(int *a, int size);
int		is_sorted(int *a, int size_a);
int		check_inst(char *str);
void	set_elements(int *a, char **n);
void	execute_inst(char *str, t_data data);
void	execute_inst_two(char *str, t_data data, t_topush_data inf);

#endif