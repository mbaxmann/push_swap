#include "../include/push_swap.h"

int	ft_check_c(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' &&
		!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_len(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
			n++;
		}
		else
			i++;
	}
	return (n);
}

void	ft_get_num(int	*ret, char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j <= ret[0] && str[i])
	{
		while (str[i] == ' ')
			i++;
		ret[j] = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
		j++;
	}
}

int	ft_check_double(int *tab)
{
	int i;
	int j;

	i = 1;
	j = i + 1;
	while (i <= tab[0])
	{
		while (j <= tab[0])
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	*ft_ps_init(char **av)
{
	int	*ret;
	int	len;

	ret = NULL;
	if (av[1])
	{
		if (ft_check_c(av[1]))
			return (NULL);
		len = ft_get_len(av[1]);
		ret = (int *)malloc(sizeof(int) * (len + 1));
		ret[0] = len;
		ft_get_num(ret, av[1]);
		if (ft_check_double(ret))
		{
			free(ret);
			ret = NULL;
		}
	}
	return (ret);	
}
