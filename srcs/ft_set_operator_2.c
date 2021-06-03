#include "../include/push_swap.h"

void	ft_pa(int *stack_A, int *stack_B)
{
	int	i;

	i = stack_A[0];
	if (stack_B[0])
	{
		while (i)
		{
			stack_A[i + 1] = stack_A[i];
			i--;
		}
		stack_A[1] = stack_B[1];
		i = 1;
		while (i < stack_B[0])
		{
			stack_B[i] = stack_B[i + 1];
			i--;
		}
		stack_A[0]++;
		stack_B[0]--;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(int *stack_A, int *stack_B)
{
	int	i;

	i = stack_B[0];
	if (stack_A[0])
	{
		while (i)
		{
			stack_B[i + 1] = stack_B[i];
			i--;
		}
		stack_B[1] = stack_A[1];
		i = 1;
		while (i < stack_A[0])
		{
			stack_A[i] = stack_A[i + 1];
			i++;
		}
		stack_B[0]++;
		stack_A[0]--;
	}
	write(1, "pb\n", 3);
}

void	ft_ra(int *stack_A, int *stack_B)
{
	int	i;
	int	j;

	j = 1;
	stack_B[0] = stack_B[0];
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
	write(1, "ra\n", 3);
}

void	ft_rb(int *stack_A, int *stack_B)
{
	int     i;
	int     j;

	j = 1;
	stack_A[0] = stack_A[0];
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
	write(1, "rb\n", 3);
}

