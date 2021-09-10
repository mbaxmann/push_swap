#include "../include/push_swap.h"

void	ft_get_biggest(int *stack_A, t_num *pack, int chunk)
{
	int	i;
	int	j;
	int	stock;

	i = 1;
	j = 1;
	stock = 0;
	pack[0].value = stack_A[1];
	pack[0].pos = 1;
	while (i <= stack_A[0])
	{
		if (stack_A[i] > pack[0].value)
		{
			pack[0].value = stack_A[i];
			pack[0].pos = i;
		}
		i++;
	}
	while (j < chunk && j < stack_A[0])
	{
		i = 1;
		while (i <= stack_A[0])
		{
			if (stack_A[i] < pack[j - 1].value)
			{
				pack[j].value = stack_A[i];
				pack[j].pos = i;
			}
			i++;
		}
		i = 1;
		while (i <= stack_A[0])
		{
			if (stack_A[i] > pack[j].value
			&& stack_A[i] < pack[j - 1].value)
			{
				pack[j].value = stack_A[i];
				pack[j].pos = i;
			}
			i++;
		}
		j++;
	}
}

void	ft_update_pos(int *stack_A, t_num *pack, int chunk)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < chunk)
	{
		if (pack[j].pos != -1)
		{
			while (i <= stack_A[0])
			{
				if (stack_A[i] == pack[j].value)
					pack[j].pos = i;
				i++;
			}
		}
		i = 1;
		j++;
	}
}

int	ft_posrel(int	l, int i)
{
	if (i < 0)
		return (i);
	else if (i < (l / 2))
		return (l - i);
	else
		return(i);
}

int	ft_find_first(t_num *pack, int *stack_A, int chunk)
{
	int *pos;
	int	i;
	int	j;

	i = -1;
	j = 0;
	pos = (int *)malloc(sizeof(int) * chunk);
	while (++i < chunk)
		pos[i] = ft_posrel(stack_A[0], pack[i].pos);
	//printf("pos1 : %d	pos2: %d	pos3: %d\n", pos1, pos2, pos3);
	i = 0;
	while (i < chunk)
	{
		while (((pos[i] >= pos[j])
			|| pos[j] == -1) && j < chunk)
			j++;
		if (j == chunk && pos[i] != -1)
			return (i);
		i++;
		j = 0;
	}
	free(pos);
	return (0);
}

int	ft_from_stack(int *stack, t_num *pack, int n, int chunk)
{
	int i;

	i = 0;
	while (i < chunk)
	{
		if (pack[i].value == stack[n])
			return (1);
		i++;
	}
	return (0);
}

void	ft_push_pack(int *stack_A, int *stack_B, t_num *pack, int chunk)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = ft_find_first(pack, stack_A, chunk);
	while (i < chunk && stack_A[0])
	{
		//printf("le J: %d\n", j);
		l = stack_A[0] / 2;
		//ft_prep_stack(stack_A, stack_B, pack);
		while (stack_A[1] != pack[j].value)
		{
			//printf("TEST		%d	st: %d\n", pack[j].pos, stack_A[0]);
			if (pack[j].pos >= l)
				ft_rra(stack_A, stack_B);
			else
				ft_ra(stack_A, stack_B);
		}
		//ft_prep_stack(stack_A, stack_B, pack);
		ft_pb(stack_A, stack_B);
		pack[j].pos = -1;
		ft_update_pos(stack_A, pack, chunk);
		j = ft_find_first(pack, stack_A, chunk);
		i++;
	}
	//if (stack_B[0])
	//	ft_smallest_attop(stack_A, stack_B, pack);
}

void	ft_sort_big(int *stack_A, int *stack_B)
{
	t_num	*pack;
	int	i = 0;
	int	chunk;

	chunk = stack_A[0] / 11;
	pack = (t_num *)malloc(sizeof(t_num) * chunk);
	while (stack_A[0])
	{
		//printf("AAAAAA			%d		\n", stack_A[0]);
		ft_get_biggest(stack_A, pack, chunk);
		/*while (i < chunk)
		{
			printf("v%d: %d p%d: %d\n", i, pack[i].value, i, pack[i].pos);
			i++;
		}*/
		i = 0;
		if (stack_B[0] == 3)
			ft_case_3(stack_A, stack_B);
		ft_push_pack(stack_A, stack_B, pack, chunk);
	}
	free(pack);
	ft_push_to_a(stack_A, stack_B);
}
