/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:00 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 15:45:43 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_to_a(int *stack_a, int *stack_b)
{
	t_num	biggest;

	while (stack_b[0])
	{
		biggest.pos = ft_find_biggest(stack_b);
		biggest.value = stack_b[biggest.pos];
		while (stack_b[1] != biggest.value)
		{
			if (biggest.pos < (stack_b[0] / 2))
				ft_rb(stack_a, stack_b);
			else
				ft_rrb(stack_a, stack_b);
		}
		ft_pa(stack_a, stack_b);
	}
}

void	ft_quicksort(int *stack_a, int *stack_b)
{
	ft_quick(stack_a, stack_b);
	if (stack_a[0] == 3)
		ft_case_3(stack_a, stack_b);
	else if (stack_a[0] == 2 && stack_a[1] > stack_a[2])
		ft_sa(stack_a, stack_b);
	ft_push_to_a(stack_a, stack_b);
}

void	ft_quick(int *stack_a, int *stack_b)
{
	static int	first_median;

	first_median = 0;
	if (stack_a[0] > 3)
	{
		if (!first_median)
			first_median = ft_sortsplit(stack_a, stack_b);
		else
			ft_sortsplit(stack_a, stack_b);
		ft_quick(stack_a, stack_b);
	}
}
