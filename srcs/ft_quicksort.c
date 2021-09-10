#include "../include/push_swap.h"

int     ft_isbiggest(int *stack_A, int nb)
{
        int     i;

        i = 1;
        while (i <= stack_A[0])
        {
                if (stack_A[i] > stack_A[nb])
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

int	ft_find_median(int *stack_A)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 1;
	k = 0;
	while (i <= stack_A[0])
	{
		while (j <= stack_A[0])
		{
			if (stack_A[j] < stack_A[i])
				k++;
			j++;
		}
		j = 1;
		if (k == (stack_A[0] / 2) - 1)
			return (i);
		k = 0;
		i++;
	}
	return (i);
}

int	ft_sortsplit(int *stack_A, int *stack_B)
{
	int median;
	int size;
	int pushed;

	pushed = 0;
	size = (stack_A[0] / 2);
	median = stack_A[ft_find_median(stack_A)];
	//printf("median :%d	Asize: %d\n", median, size);
	while (pushed < size)
	{
		if (stack_A[1] <= median)
		{
			ft_pb(stack_A, stack_B);
			pushed++;
		}
		else
			ft_ra(stack_A, stack_B);
	}
	return (median);
}

void	ft_push_to_a(int *stack_A, int *stack_B)
{
	t_num biggest;

	while (stack_B[0])
	{
		biggest.pos = ft_find_biggest(stack_B);
		biggest.value = stack_B[biggest.pos];
		//printf("nb: %d\n", biggest.value);
		while (stack_B[1] != biggest.value)
		{
			if (biggest.pos < (stack_B[0] / 2))
				ft_rb(stack_A, stack_B);
			else
				ft_rrb(stack_A, stack_B);
		}
		ft_pa(stack_A, stack_B);
	}
}

void	ft_quicksort(int *stack_A, int *stack_B)
{

	ft_quick(stack_A, stack_B);
	if (stack_A[0] == 3)
		ft_case_3(stack_A, stack_B);
	else if (stack_A[0] == 2 && stack_A[1] > stack_A[2])
		ft_sa(stack_A, stack_B);
	ft_push_to_a(stack_A, stack_B);
}

void	ft_quick(int *stack_A, int *stack_B)
{
	static int	first_median;

	first_median = 0;
	if (stack_A[0] > 3)
	{
		if (!first_median)
			first_median = ft_sortsplit(stack_A, stack_B);
		else
			ft_sortsplit(stack_A, stack_B);
		ft_quick(stack_A, stack_B);
	}
}

int	ft_allgreater(int *stack_A, int pivot)
{
	int	i;

	i = 1;
	while (i <= stack_A[0])
	{
		if (stack_A[i] < pivot)
			return (0);
		i++;
	}
	return (1);
}

