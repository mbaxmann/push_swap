/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:17:08 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 15:45:22 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_settnum(t_num *to_set, int value, int pos)
{
	to_set->value = value;
	to_set->pos = pos;
}

void	ft_get_biggest(int *stack_a, t_num *pack, int chunk)
{
	int	i;
	int	j;
	int	stock;

	i = 0;
	j = 1;
	stock = 0;
	ft_settnum(&pack[0], stack_a[1], 1);
	while (++i <= stack_a[0])
		if (stack_a[i] > pack[0].value)
			ft_settnum(&pack[0], stack_a[i], i);
	while (j < chunk && j < stack_a[0])
	{
		i = 0;
		while (++i <= stack_a[0])
			if (stack_a[i] < pack[j - 1].value)
				ft_settnum(&pack[j], stack_a[i], i);
		i = 0;
		while (++i <= stack_a[0])
			if (stack_a[i] > pack[j].value
				&& stack_a[i] < pack[j - 1].value)
				ft_settnum(&pack[j], stack_a[i], i);
		j++;
	}
}

void	ft_update_pos(int *stack_a, t_num *pack, int chunk)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < chunk)
	{
		if (pack[j].pos != -1)
		{
			while (i <= stack_a[0])
			{
				if (stack_a[i] == pack[j].value)
					pack[j].pos = i;
				i++;
			}
		}
		i = 1;
		j++;
	}
}

int	ft_posrel(int l, int i)
{
	if (i < 0)
		return (i);
	else if (i < (l / 2))
		return (l - i);
	else
		return (i);
}
