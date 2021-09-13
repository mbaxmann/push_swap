/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_operator_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:51:39 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 15:54:42 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rr(int *stack_a, int *stack_b)
{
	int	i;
	int	j;

	j = 0;
	if (stack_a[0])
	{
		i = stack_a[1];
		while (++j < stack_a[0])
		{
			stack_a[j] = stack_a[j + 1];
		}
		stack_a[j] = i;
	}
	j = 0;
	if (stack_b[0])
	{
		i = stack_b[1];
		while (++j < stack_b[0])
		{
			stack_b[j] = stack_b[j + 1];
		}
		stack_b[j] = i;
	}
	write(1, "rr\n", 3);
}

void	ft_rra(int *stack_a, int *stack_b)
{
	int	i;
	int	j;

	j = stack_a[0];
	stack_b[0] = stack_b[0];
	if (stack_a[0])
	{
		i = stack_a[stack_a[0]];
		while (j > 1)
		{
			stack_a[j] = stack_a[j - 1];
			j--;
		}
		stack_a[1] = i;
	}
	write(1, "rra\n", 4);
}

void	ft_rrb(int *stack_a, int *stack_b)
{
	int	i;
	int	j;

	j = stack_b[0];
	stack_a[0] = stack_a[0];
	if (stack_b[0])
	{
		i = stack_b[stack_b[0]];
		while (j > 1)
		{
			stack_b[j] = stack_b[j - 1];
			j--;
		}
		stack_b[1] = i;
	}
	write(1, "rrb\n", 4);
}

void	ft_rrr(int *stack_a, int *stack_b)
{
	int	i;
	int	j;

	j = stack_a[0] + 1;
	if (stack_a[0])
	{
		i = stack_a[stack_a[0]];
		while (--j > 1)
		{
			stack_a[j] = stack_a[j - 1];
		}
		stack_a[j] = i;
	}
	j = stack_b[0] + 1;
	if (stack_b[0])
	{
		i = stack_b[stack_b[0]];
		while (--j > 1)
		{
			stack_b[j] = stack_b[j - 1];
		}
		stack_b[j] = i;
	}
	write(1, "rrr\n", 4);
}
