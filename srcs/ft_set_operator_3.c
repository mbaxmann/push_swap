#include "../include/push_swap.h"

void	ft_rr(int *stack_A, int *stack_B)
{
	int	i;
	int	j;

	j = 1;
	if (stack_A[0])
	{
		i = stack_A[1];
		while (j < stack_A[0])
		{
			stack_A[j] = stack_A[j + 1];
			j++;
		}
		stack_A[j] = i;
	}
	j = 1;
	if (stack_B[0])
	{
		i = stack_B[1];
		while (j < stack_B[0])
		{
			stack_B[j] = stack_B[j + 1];
			j++;
		}
		stack_B[j] = i;
	}
	write(1, "rr\n", 3);
	count_ope++;
}

void	ft_rra(int *stack_A, int *stack_B)
{
	int	i;
	int	j;

	j = stack_A[0];
	stack_B[0] = stack_B[0];
	if (stack_A[0])
	{
		i = stack_A[stack_A[0]];
		while (j > 1)
		{
			stack_A[j] = stack_A[j - 1];
			j--;
		}
		stack_A[1] = i;
	}
	write(1, "rra\n", 4);
	count_ope++;
}

void	ft_rrb(int *stack_A, int *stack_B)
{
	int     i;
	int     j;

	j = stack_B[0];
	stack_A[0] = stack_A[0];
	if (stack_B[0])
	{
		i = stack_B[stack_B[0]];
		while (j > 1)
		{
			stack_B[j] = stack_B[j - 1];
			j--;
		}
		stack_B[1] = i;
	}
	write(1, "rrb\n", 4);
	count_ope++;
}

void	ft_rrr(int *stack_A, int *stack_B)
{
	int	i;
	int	j;

	j = stack_A[0];
	if (stack_A[0])
	{
		i = stack_A[stack_A[0]];
		while (j > 1)
		{
			stack_A[j] = stack_A[j - 1];
			j--;
		}
		stack_A[j] = i;
	}
	j = stack_B[0];
	if (stack_B[0])
	{
		i = stack_B[stack_B[0]];
		while (j > 1)
		{
			stack_B[j] = stack_B[j - 1];
			j--;
		}
		stack_B[j] = i;
	}
	write(1, "rrr\n", 4);
	count_ope++;
}
