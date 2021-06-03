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
			printf("stack_A: %d ", stack_A[i]);
		else
			printf("stack_A: NULL ");
		if (j <= stack_B[0])
			printf("stack_B: %d\n", stack_B[j]);
		else
			printf("stack_A: NULL\n");
		len--;
		i++;
		j++;
	}
}

void	ft_algo(int *stack_A)
{
	int	*stack_B;
	void (*operator[11]) (int *, int *);

	stack_B = (int *)malloc(sizeof(int) * (stack_A[0] + 1));
	ft_bzero(stack_B, stack_A[0] + 1);
	ft_set_operator(operator);
	operator[PB](stack_A, stack_B);
	operator[PB](stack_A, stack_B);
	//operator[RR](stack_A, stack_B);
	ft_test(stack_A, stack_B);
}
