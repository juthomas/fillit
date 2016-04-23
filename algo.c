/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:29:49 by zzeller           #+#    #+#             */
/*   Updated: 2016/04/04 16:44:18 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short	place(short solovarmax, short i, t_list *list, char *map)
{
	short	x;
	short	u;

	u = 0;
	x = root(solovarmax);
	while (u < 4)
	{
		if (map[(i % x + list->x[u]) + (list->y[u] * x + i / x * x)] != '.')
			return (0);
		if (i % x + list->x[u] >= x)
			return (0);
		if (i / x + list->y[u] >= x)
			return (0);
		u++;
	}
	return (1);
}

char	*rmtetri(char *map, t_list *list, short solovarmax, int i)
{
	short	u;
	short	x;

	x = root(solovarmax);
	u = 0;
	while (u < 4)
	{
		map[(i % x + list->x[u]) + (list->y[u] * x + i / x * x)] = '.';
		u++;
	}
	return (map);
}

short	recusive(t_list *list, short solovarmax, short i, char *map)
{
	while (i < solovarmax)
	{
		if (place(solovarmax, i, list, map) == 1)
		{
			map = printmap(map, list, solovarmax, i);
			if (list->next == NULL)
			{
				putmap(map, solovarmax);
				return (1);
			}
			if (recusive(list->next, solovarmax, 0, map) == 1)
				return (1);
			else
				map = rmtetri(map, list, solovarmax, i);
		}
		i++;
	}
	return (0);
}

char	*fildot(char *map, short solovarmax)
{
	short	i;

	i = 0;
	while (i < solovarmax)
	{
		map[i] = '.';
		i++;
	}
	return (map);
}

t_var	resolution(t_var var)
{
	t_list	*list;
	char	*map;

	list = var.begin;
	var.size = 0;
	while (var.size * var.size < var.nbp * 4)
		var.size++;
	var.solovarmax = var.size * var.size;
	var.solovar = 0;
	while (var.solovarmax <= 196)
	{
		map = (char*)malloc(sizeof(char) * var.solovarmax);
		map[var.solovarmax] = '\0';
		map = fildot(map, var.solovarmax);
		if (recusive(list, var.solovarmax, 0, map) == 1)
			return (var);
		free(map);
		var.solovarmax = ++var.size * var.size;
	}
	return (var);
}
