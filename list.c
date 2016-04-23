/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:44:21 by zzeller           #+#    #+#             */
/*   Updated: 2016/04/04 17:02:14 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*list_xy(char *tab, t_list *list, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 21)
	{
		if (tab[i] == '#')
		{
			list->x[j] = x;
			list->y[j] = y;
			j++;
		}
		if (i % 5 == 4)
		{
			x = -1;
			y++;
		}
		x++;
		i++;
	}
	return (list);
}

t_list			*create_elem(char *tab)
{
	int			x;
	int			y;
	t_list		*list;

	x = 0;
	y = 0;
	list = (t_list*)malloc(sizeof(t_list));
	list = list_xy(tab, list, x, y);
	if (list)
		list->next = NULL;
	return (list);
}

char			*modif_column(char *tab)
{
	int			i;

	i = 0;
	while (i < 21)
	{
		if (i % 5 != 0)
		{
			tab[i - 1] = tab[i];
		}
		if (i % 5 == 4 && i != 0 && i < 21)
		{
			tab[i] = '-';
		}
		i++;
	}
	tab[20] = '-';
	return (tab);
}

char			*modif_line(char *tab)
{
	int			i;

	i = 0;
	while (i < 21)
	{
		while (i < 5)
			i++;
		tab[i - 5] = tab[i];
		i++;
	}
	i = 15;
	while (i < 21)
	{
		tab[i] = '-';
		i++;
	}
	return (tab);
}

t_list			*fillist(char *tmp, char l)
{
	t_list		*list;
	t_list		*lst;
	short		stop;
	int			n;

	n = 0;
	stop = 1;
	list = NULL;
	lst = NULL;
	tmp = modif_y(tmp);
	list = create_elem(tmp);
	lst = list;
	while (lst->next != NULL)
		lst = lst->next;
	list->l = l;
	return (list);
}
