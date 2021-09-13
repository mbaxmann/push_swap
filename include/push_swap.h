/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:01:41 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 18:22:53 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_num
{
	int	value;
	int	pos;
}	t_num;

int		*ft_ps_init(int ac, char **av);
int		ft_check_c(int ac, char **str);
int		ft_get_len(int ac, char **str);
int		ft_check_double(int *tab);
int		ft_issort(int *stack_A);
int		ft_find_first(t_num *pack, int *stack_A, int chunk);
int		ft_posrel(int l, int i);
int		ft_get_num(int	*ret, int ac, char **str);
void	ft_algo(int *stack_A);
void	ft_sort_big(int *stack_A, int *stack_B);
void	ft_get_biggest(int *stack_A, t_num *pack, int chunk);
void	ft_push_pack(int *stack_A, int *stack_B, t_num *pack, int chunk);
void	ft_update_pos(int *stack_A, t_num *pack, int chunk);
void	ft_case_3(int *stack_A, int *stack_B);
void	ft_insert(int *stack_A, int *stack_B);
void	ft_sa(int *stack_A, int *stack_B);
void	ft_sb(int *stack_A, int *stack_B);
void	ft_ss(int *stack_A, int *stack_B);
void	ft_pa(int *stack_A, int *stack_B);
void	ft_pb(int *stack_A, int *stack_B);
void	ft_ra(int *stack_A, int *stack_B);
void	ft_rb(int *stack_A, int *stack_B);
void	ft_rr(int *stack_A, int *stack_B);
void	ft_rra(int *stack_A, int *stack_B);
void	ft_rrb(int *stack_A, int *stack_B);
void	ft_rrr(int *stack_A, int *stack_B);
void	ft_swap(int *stack_A, int *stack_B, int *smaller, int *i);
int		ft_sortt(int *stack_A, int *stack_B, int low, int high);
void	ft_quicksort(int *stack_A, int *stack_B);
void	ft_quick(int *stack_A, int *stack_B);
void	ft_push_to_a(int *stack_A, int *stack_B);
int		ft_find_biggest(int *stack);
int		ft_isbiggest(int *stack_A, int nb);
int		ft_sortsplit(int *stack_A, int *stack_B);
int		ft_find_median(int *stack_A);

#endif
