/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:37:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 15:43:52 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_issort(int *stack_a)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i <= stack_a[0])
	{
		while (j <= stack_a[0])
		{
			if (stack_a[i] > stack_a[j])
			{
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_case_3(int *stack_a, int *stack_b)
{
	if (stack_a[1] > stack_a[2] && stack_a[1] < stack_a[3]
		&& stack_a[1] < stack_a[3])
		ft_sa(stack_a, stack_b);
	else if (stack_a[1] > stack_a[2] && stack_a[1] > stack_a[3]
		&& stack_a[2] > stack_a[3])
	{
		ft_sa(stack_a, stack_b);
		ft_rra(stack_a, stack_b);
	}
	else if (stack_a[1] > stack_a[2] && stack_a[1] > stack_a[3]
		&& stack_a[2] < stack_a[3])
		ft_ra(stack_a, stack_b);
	else if (stack_a[1] < stack_a[2] && stack_a[1] < stack_a[3]
		&& stack_a[2] > stack_a[3])
	{
		ft_sa(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
	}
	else if (stack_a[1] < stack_a[2] && stack_a[1] > stack_a[3]
		&& stack_a[2] > stack_a[3])
		ft_rra(stack_a, stack_b);
}

void	ft_algo(int *stack_a)
{
	int	*stack_b;

	stack_b = (int *)malloc(sizeof(int) * (stack_a[0] + 1));
	ft_bzero(stack_b, stack_a[0] + 1);
	if (!ft_issort(stack_a))
	{
		if (stack_a[0] <= 200)
			ft_quicksort(stack_a, stack_b);
		else
			ft_sort_big(stack_a, stack_b);
	}
}
