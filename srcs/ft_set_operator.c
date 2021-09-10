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
	count_ope++;
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
	count_ope++;
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
	count_ope++;
}
