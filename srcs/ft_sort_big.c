/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:13:53 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 18:53:05 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_first(t_num *pack, int *stack_a, int chunk)
{
	int	*pos;
	int	i;
	int	j;

	i = -1;
	j = 0;
	pos = (int *)malloc(sizeof(int) * chunk);
	while (++i < chunk)
		pos[i] = ft_posrel(stack_a[0], pack[i].pos);
	i = 0;
	while (i < chunk)
	{
		while (((pos[i] >= pos[j])
				|| pos[j] == -1) && j < chunk)
			j++;
		if (j == chunk && pos[i] != -1)
		{
			free(pos);
			return (i);
		}
		i++;
		j = 0;
	}
	free(pos);
	return (0);
}

int	ft_from_stack(int *stack, t_num *pack, int n, int chunk)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (pack[i].value == stack[n])
			return (1);
		i++;
	}
	return (0);
}

void	ft_push_pack(int *stack_a, int *stack_b, t_num *pack, int chunk)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = ft_find_first(pack, stack_a, chunk);
	while (i < chunk && stack_a[0])
	{
		l = stack_a[0] / 2;
		while (stack_a[1] != pack[j].value)
		{
			if (pack[j].pos >= l)
				ft_rra(stack_a, stack_b);
			else
				ft_ra(stack_a, stack_b);
		}
		ft_pb(stack_a, stack_b);
		pack[j].pos = -1;
		ft_update_pos(stack_a, pack, chunk);
		j = ft_find_first(pack, stack_a, chunk);
		i++;
	}
}

void	ft_sort_big(int *stack_a, int *stack_b)
{
	int			chunk;
	t_num		*pack;

	chunk = stack_a[0] / 11;
	pack = (t_num *)malloc(sizeof(t_num) * chunk);
	while (stack_a[0])
	{
		ft_get_biggest(stack_a, pack, chunk);
		if (stack_b[0] == 3)
			ft_case_3(stack_a, stack_b);
		ft_push_pack(stack_a, stack_b, pack, chunk);
	}
	free(pack);
	ft_push_to_a(stack_a, stack_b);
}
