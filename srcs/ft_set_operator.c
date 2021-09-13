/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:49:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 15:55:07 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(int *stack_a, int *stack_b)
{
	int	i;

	stack_b[0] = stack_b[0];
	if (stack_a[0] > 1)
	{
		i = stack_a[1];
		stack_a[1] = stack_a[2];
		stack_a[2] = i;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(int *stack_a, int *stack_b)
{
	int	i;

	stack_a[0] = stack_a[0];
	if (stack_b[0] > 1)
	{
		i = stack_b[1];
		stack_b[1] = stack_b[2];
		stack_b[2] = i;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(int *stack_a, int *stack_b)
{
	int	i;

	if (stack_b[0] > 1)
	{
		i = stack_b[1];
		stack_b[1] = stack_b[2];
		stack_b[2] = i;
	}
	if (stack_a[0] > 1)
	{
		i = stack_a[1];
		stack_a[1] = stack_a[2];
		stack_a[2] = i;
	}
	write(1, "ss\n", 3);
}
