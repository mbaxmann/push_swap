/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:28:39 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 15:45:33 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isbiggest(int *stack_a, int nb)
{
	int	i;

	i = 1;
	while (i <= stack_a[0])
	{
		if (stack_a[i] > stack_a[nb])
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_biggest(int *stack)
{
	int	i;

	i = 1;
	while (i <= stack[0])
	{
		if (ft_isbiggest(stack, i))
			return (i);
		i++;
	}
	return (0);
}

int	ft_find_median(int *stack_a)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 1;
	k = 0;
	while (i <= stack_a[0])
	{
		while (j <= stack_a[0])
		{
			if (stack_a[j] < stack_a[i])
				k++;
			j++;
		}
		j = 1;
		if (k == (stack_a[0] / 2) - 1)
			return (i);
		k = 0;
		i++;
	}
	return (i);
}

int	ft_sortsplit(int *stack_a, int *stack_b)
{
	int	median;
	int	size;
	int	pushed;

	pushed = 0;
	size = (stack_a[0] / 2);
	median = stack_a[ft_find_median(stack_a)];
	while (pushed < size)
	{
		if (stack_a[1] <= median)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a, stack_b);
	}
	return (median);
}
