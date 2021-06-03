#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

enum	ope { SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

int	*ft_ps_init(char **av);
int	ft_check_c(char *str);
int	ft_get_len(char *str);
int	ft_check_double(int *tab);
void	ft_get_num(int	*ret, char *str);
void	ft_algo(int *stack_A);
void	ft_set_operator(void (*tab[11])(int *, int *));
void	ft_sa(int *stack_A, int * stack_B);
void    ft_sb(int *stack_A, int * stack_B);
void    ft_ss(int *stack_A, int * stack_B);
void    ft_pa(int *stack_A, int * stack_B);
void    ft_pb(int *stack_A, int * stack_B);
void    ft_ra(int *stack_A, int * stack_B);
void    ft_rb(int *stack_A, int * stack_B);
void    ft_rr(int *stack_A, int * stack_B);
void    ft_rra(int *stack_A, int * stack_B);
void    ft_rrb(int *stack_A, int * stack_B);
void    ft_rrr(int *stack_A, int * stack_B);

#endif
