#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int *stack_A;

	if (ac < 2)
		return (0);
	if (ac > 2 )
	{
		write(1, "error\n", 6);
                return (1);
	}
	else if ((int)(stack_A = ft_ps_init(av)) > 1)
	{
		write(1, "success\n", 8);
		ft_algo(stack_A);
		return (0);
	}
	else if (stack_A == 0)
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (0);
}
