/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:33:53 by zzeller           #+#    #+#             */
/*   Updated: 2016/04/04 17:02:56 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

short	root(short i)
{
	short	u;

	u = 1;
	while (u * u != i)
		u++;
	return (u);
}

void	putmap(char *map, short solovarmax)
{
	short	i;
	short	x;

	x = root(solovarmax);
	i = 0;
	while (i < solovarmax)
	{
		ft_putchar(map[i]);
		if (i % x == x - 1)
			ft_putchar('\n');
		i++;
	}
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*printmap(char *map, t_list *list, short solovarmax, int i)
{
	short	u;
	short	x;

	x = root(solovarmax);
	u = 0;
	while (u < 4)
	{
		map[(i % x + list->x[u]) + (list->y[u] * x + i / x * x)] = list->l;
		u++;
	}
	return (map);
}
