/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:37:01 by zzeller           #+#    #+#             */
/*   Updated: 2016/04/04 16:37:21 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*modif_x(char *tab)
{
	short		i;
	short		ok;

	ok = 0;
	i = 0;
	while (i < 21 && ok == 0)
	{
		while (i % 5 != 4)
		{
			if (tab[i] == '#')
				ok = 1;
			i++;
		}
		if (tab[i] == '#')
			ok = 1;
		if (ok == 0)
		{
			tab = modif_line(tab);
			i = 0;
		}
	}
	return (tab);
}

char			*modif_y(char *tab)
{
	short		i;
	short		ok;

	ok = 0;
	i = 0;
	tab = modif_x(tab);
	while (i < 21 && ok == 0)
	{
		if (i % 5 == 0)
		{
			if (tab[i] == '#')
				ok = 1;
		}
		if (i == 20)
		{
			tab = modif_column(tab);
			i = -1;
		}
		i++;
	}
	return (tab);
}
