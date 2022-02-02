/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:53 by atouba            #+#    #+#             */
/*   Updated: 2022/02/02 13:18:56 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft/libft.h"
#include <stdio.h>

void	swap(t_list	*root);
void	push(t_list **from, t_list **to);
void	rotate(t_list **root);
t_list	*reverse_r(t_list **root);
void	display(t_list	*root);
#endif
