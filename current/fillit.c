/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:32:46 by zzeller           #+#    #+#             */
/*   Updated: 2016/03/31 14:30:53 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_var	ft_read(char **argv, t_var var)
{
	int			fd;
	char		buf[22];
	short		index;
	char		l;
	t_list		*list;
	t_liste		*begin;
	int 		fst = 1;
	begin = (t_liste*)malloc(sizeof(*begin));


	index = 1;
	l = 'A';
	fd = open(argv[1], O_RDONLY);
	while (index)
	{
		index = read(fd, buf, 21);
		buf[index] = '\0';
		var = valid(var, buf);
		if (var.valid == 0)
			printf("ERROR\n");
		if (fst)
			list = fillist(buf, l);
		else
		{
			list->next = fillist(buf, l);
			list = list->next;

		}
		if (fst)
		{
			fst = 0;
		begin->beg = list;
		}
		var.nbp++;
		l++;
	}
	list = begin->beg;
	printf("test list (valeur x0) : %d\n", list->x[0]);
	printf("test list (valeur x0) : %d\n", list->next->next->next->x[0]);
	return (var);
}

int		main(int argc, char **argv)
{
	t_var	var;

	var.nbp = 0;
	var.link = 0;
	var.valid = 0;
	if (argc == 2)
	{
		var = ft_read(argv, var);
	}
	return (0);
}
