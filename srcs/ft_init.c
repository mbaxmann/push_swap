/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:49:02 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 18:13:43 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_c(int ac, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < ac)
	{
		while (str[j][i])
		{
			if (str[j][i] != ' ' &&
			str[j][i] != '-' &&
			!ft_isdigit(str[j][i]))
				return (1);
			i++;
			if ((str[j][i] == '-' || str[j][i] == '+')
			&& !ft_isdigit(str[j][i + 1]))
				return (1);
		}
		j++;
		i = 0;
	}
	return (0);
}

int	ft_get_len(int ac, char **str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 1;
	n = 0;
	while (j < ac)
	{
		while (str[j][i])
		{
			if (ft_isdigit(str[j][i]))
			{
				while (ft_isdigit(str[j][i]))
					i++;
				n++;
			}
			else
				i++;
		}
		i = 0;
		j++;
	}
	return (n);
}

int	ft_get_num(int	*ret, int ac, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (++k < ac)
	{
		while (j <= ret[0] && str[k][i])
		{
			while (str[k][i] == ' ')
				i++;
			ret[j] = ft_atoi(str[k] + i);
			if ((ret[j] == -1 || ret[j] == 0) && ft_strlen(str[k]) > 3)
				return (-1);
			if (str[k][i] == '-')
				i++;
			while (ft_isdigit(str[k][i]))
				i++;
			j++;
		}
		i = 0;
	}
	return (0);
}

int	ft_check_double(int *tab)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (i <= tab[0])
	{
		while (j <= tab[0])
		{
			if (tab[i] == tab[j])
			{
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	*ft_ps_init(int ac, char **av)
{
	int	*ret;
	int	len;
	int	i;

	ret = NULL;
	if (av[1])
	{
		if (ft_check_c(ac, av))
			return (NULL);
		len = ft_get_len(ac, av);
		ret = (int *)malloc(sizeof(int) * (len + 1));
		ret[0] = len;
		i = ft_get_num(ret, ac, av);
		if (i == -1 || ft_check_double(ret))
		{
			free(ret);
			ret = NULL;
		}
	}
	return (ret);
}
