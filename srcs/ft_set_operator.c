#include "../include/push_swap.h"

void	ft_sa(int *stack_A, int *stack_B)
{
	int i;

	stack_B[0] = stack_B[0];
	if (stack_A[0] > 1)
	{
		i = stack_A[1];
		stack_A[1] = stack_A[2];
		stack_A[2] = i;
	}
	write(1, "sa\n", 3);
}

void    ft_sb(int *stack_A, int *stack_B)
{
	int i;

	stack_A[0] = stack_A[0];
	if (stack_B[0] > 1)
	{
		i = stack_B[1];
		stack_B[1] = stack_B[2];
		stack_B[2] = i;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(int *stack_A, int *stack_B)
{
	int i;

	if (stack_B[0] > 1)
	{
		i = stack_B[1];
		stack_B[1] = stack_B[2];
		stack_B[2] = i;
	}
	if (stack_A[0] > 1)
	{
		i = stack_A[1];
		stack_A[1] = stack_A[2];
		stack_A[2] = i;
	}
	write(1, "ss\n", 3);
}

void	ft_set_operator(void (*tab[11])(int *, int *))
{
	tab[0] = ft_sa;
	tab[1] = ft_sb;
	tab[2] = ft_ss;
	tab[3] = ft_pa;
	tab[4] = ft_pb;
	tab[5] = ft_ra;
	tab[6] = ft_rb;
	tab[7] = ft_rr;
	tab[8] = ft_rra;
	tab[9] = ft_rrb;
	tab[10] = ft_rrr;
}
