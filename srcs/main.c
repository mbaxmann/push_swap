/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:56:14 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/14 14:23:50 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = ft_ps_init(ac, av);
	if ((int)stack_a > 0)
	{
		ft_algo(stack_a);
		return (0);
	}
	else if (stack_a == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
