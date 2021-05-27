#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

int	*ft_ps_init(char **av);
int	ft_check_c(char *str);
int	ft_get_len(char *str);
void	ft_get_num(int	*ret, char *str);

#endif
