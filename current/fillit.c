/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:32:46 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/31 14:30:53 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	testeur_de_liste(t_list *list)
{
	int k = 0;
	int m = 0;
	while (list->next)
	{
		printf("letter : %c\n", list->l);
		
		printf("piece : \n");
		while (k < 16)
		{
			if (list->x[m] == k % 4 && list->y[m] == k / 4)
			{
				printf("#");
				m++;
			}
			else
				printf(".");
			k++;
			if (k % 4 == 0)
				printf("\n");
		}
		k = 0;
		m = 0;
		list = list->next;
	}


}

t_var	ft_read(char **argv, t_var var)
{
	int			fd;
	char		buf[22];
	short		index;
	char		l;
	t_list		*list;
//	t_liste		*begin;
	int 		fst = 1;
//	begin = (t_liste*)malloc(sizeof(*begin));


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
			var.begin = list;
	//	begin->beg = list;
		}
		var.nbp++;
		l++;
	}
	//list = begin->beg;
	list = var.begin;
	testeur_de_liste(list);
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
