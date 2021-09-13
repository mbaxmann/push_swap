/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_operator_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:50:35 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 15:55:45 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pa(int *stack_a, int *stack_b)
{
	int	i;

	i = stack_a[0];
	if (stack_b[0])
	{
		while (i)
		{
			stack_a[i + 1] = stack_a[i];
			i--;
		}
		stack_a[1] = stack_b[1];
		i = 1;
		while (i < stack_b[0])
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_a[0]++;
		stack_b[0]--;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(int *stack_a, int *stack_b)
{
	int	i;

	i = stack_b[0];
	if (stack_a[0])
	{
		while (i)
		{
			stack_b[i + 1] = stack_b[i];
			i--;
		}
		stack_b[1] = stack_a[1];
		i = 1;
		while (i < stack_a[0])
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_b[0]++;
		stack_a[0]--;
	}
	write(1, "pb\n", 3);
}

void	ft_ra(int *stack_a, int *stack_b)
{
	int	i;
	int	j;

	j = 1;
	stack_b[0] = stack_b[0];
	if (stack_a[0])
	{
		i = stack_a[1];
		while (j < stack_a[0])
		{
			stack_a[j] = stack_a[j + 1];
			j++;
		}
		stack_a[j] = i;
	}
	write(1, "ra\n", 3);
}

void	ft_rb(int *stack_a, int *stack_b)
{
	int	i;
	int	j;

	j = 1;
	stack_a[0] = stack_a[0];
	if (stack_b[0])
	{
		i = stack_b[1];
		while (j < stack_b[0])
		{
			stack_b[j] = stack_b[j + 1];
			j++;
		}
		stack_b[j] = i;
	}
	write(1, "rb\n", 3);
}
