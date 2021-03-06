/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:53 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:14:21 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct data
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_data;

typedef struct topush_data
{
	int		i_from;
	int		size_from;
	char	c;
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
void	push(int *b, t_topush_data inf, int *a, int *size_a);
void	rotate(int *a, int size, char c);
void	reverse(int	*a, int size, char c);
void	lis(t_data data, int *l_d, int *l_b);
void	min_to_top(int *a, int size);
void	rot_or_rev(int *a, int ind, int size, char c);
int		lenght(t_data data, int *y, int *last_elem_ind);
int		is_dup(char **s, int to_comp, int top);
int		is_num(char *c);
int		check(char **s, int size);
int		max(int *a, int size_a);
int		min(int *a, int size_a, int choice);
int		num_of_ac(int size_a, int i);
int		best_elem_b_i(t_data data, int size_b, int size_a, int *elem_to_push);
int		elem_aft(int *a, int size_a, int n);
void	push_back(t_data data, int *l_b, int *l_a);
void	init(int *a, int size, int n);
int		ft_atoi(const char *str);
void	init_args(int *i, int *global_m, int *actions, int size_b);
void	assign_gmax_ps(t_data data, int size_a, int size_b, int *global_m);
int		max_elem(int *x, int *last_element, t_data data);
void	copy_array(int *source, int l_s, t_data data);
int		ind_min(int *a, int size);
int		is_sorted(int *a, int size_a);

#endif
