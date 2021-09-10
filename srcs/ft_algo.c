#include "../include/push_swap.h"

void	ft_test(int *stack_A, int *stack_B)
{
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	len = (stack_A[0] > stack_B[0]) ? stack_A[0] : stack_B[0];
	while (len > -1)
	{
		if (i  <= stack_A[0])
			printf("%d	stack_A: %d ", i,  stack_A[i]);
		else
			printf("%d	stack_A: NULL ", i);
		if (j <= stack_B[0])
			printf("	stack_B: %d\n", stack_B[j]);
		else
			printf("	stack_B: NULL\n");
		len--;
		i++;
		j++;
	}
	printf("Count:	%d\n", count_ope);
	if (ft_issort(stack_A))
		printf("Is sorted\n");
	else
		printf("Is NOT sorted\n");
}

int	ft_issort(int *stack_A)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i <= stack_A[0])
	{
		while (j <= stack_A[0])
		{
			if (stack_A[i] > stack_A[j])
			{
				//printf("Not sorted\n");
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	//printf("Is sorted\n");
	return (1);
}

void	ft_case_3(int *stack_A, int *stack_B)
{
	if (stack_A[1] > stack_A[2] && stack_A[1] < stack_A[3] &&
		stack_A[1] < stack_A[3])
		ft_sa(stack_A, stack_B);
	else if (stack_A[1] > stack_A[2] && stack_A[1] > stack_A[3] &&
		stack_A[2] > stack_A[3])
	{
		ft_sa(stack_A, stack_B);
		ft_rra(stack_A, stack_B);
	}
	else if (stack_A[1] > stack_A[2] && stack_A[1] > stack_A[3] &&
		stack_A[2] < stack_A[3])
		ft_ra(stack_A, stack_B);
	else if (stack_A[1] < stack_A[2] && stack_A[1] < stack_A[3] &&
		stack_A[2] > stack_A[3])
	{
		ft_sa(stack_A, stack_B);
		ft_ra(stack_A, stack_B);
	}
	else if (stack_A[1] < stack_A[2] && stack_A[1] > stack_A[3] &&
		stack_A[2] > stack_A[3])
		ft_rra(stack_A, stack_B);
}

void	ft_sort(int *stack_A, int *stack_B)
{
	int	smallest;
	int	i;
	int	place;

	i = 1;
	smallest = stack_A[1];
	while (stack_A[0] > 3)
	{
		while (i <= stack_A[0])
		{
			if (smallest > stack_A[i])
				smallest = stack_A[i];
			if (smallest == stack_A[i])
				place = i;
			i++;
		}
		while (stack_A[1] != smallest)
		{
			if (place <= (stack_A[0] / 2) && stack_A[0] % 2 == 0)
				ft_ra(stack_A, stack_B);
			else if (place <= ((stack_A[0] / 2) + 1)
				&& stack_A[0] % 2 == 1)
				ft_ra(stack_A, stack_B);
			else
				ft_rra(stack_A, stack_B);
		}
		ft_pb(stack_A, stack_B),
		i = 1;
		smallest = stack_A[1];
	}
	ft_case_3(stack_A, stack_B);
	while (stack_B[0])
	{
		ft_pa(stack_A, stack_B);
	}
	//printf("total : %d\n", count_ope);
}

void	ft_algo(int *stack_A)
{
	int	*stack_B;

	stack_B = (int *)malloc(sizeof(int) * (stack_A[0] + 1));
	ft_bzero(stack_B, stack_A[0] + 1);
	if (!ft_issort(stack_A))
	{
		//ft_quicksort(stack_A, stack_B);
		//ft_sort_big(stack_A, stack_B);
		if (stack_A[0] <= 200)
			ft_quicksort(stack_A, stack_B);
		else
			ft_sort_big(stack_A, stack_B);
	}
	//ft_issort(stack_A);
	//ft_test(stack_A, stack_B);
	//operator[PB](stack_A, stack_B);
	//operator[PB](stack_A, stack_B);
	//operator[RR](stack_A, stack_B);
	//ft_test(stack_A, stack_B);
}
