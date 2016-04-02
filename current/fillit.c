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
short	maxmaxsolovar(short nbp) // calcule la taille max
{
	printf("maxmaxsolovar :%d\n", (nbp / 2 + 3) * (nbp / 2 + 3));
	return ((nbp / 2 + 3) * (nbp / 2 + 3));
}
t_var	resolution(t_var var)
{
	var.size = 0;
	while (var.size * var.size < var.nbp * 4)
		var.size++;
	var.solovarmax = var.size * var.size;
	printf("size :%d\n", var.size);
	printf("solovar :%d\n", var.solovarmax);
	var.solovar = 0; //evite d'avoir x et y qui seront trouvables
					// par n % 5 et n / 5 (d'ou le nom solovarmax) 
	while (var.solovarmax <= maxmaxsolovar(var.nbp))
	{
		while (var.solovarmax > var.solovar)// s'arrete a solovarmax
								// moins 1 puisque solovar commmence
								// à 0
		{
			var.solovar++;
		
		}
		var.solovar = 0;
		var.solovarmax = ++var.size * var.size;
		printf("value solovar :%d\n", var.solovarmax);
	}
}

void	testeur_de_liste(t_var var)
{
	t_list *list;

	list = var.begin;
	int k = 0;
	int m = 0;
	while (list->next)
	{
		printf("\nletter : %c\n", list->l);
		
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
	printf("\n\n\nre\n\n");
	list = var.begin;
	while (list->next)
	{
		printf("\nletter : %c\n", list->l);
		
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
	int 		fst = 1;
	int			nbofpie = 0;

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
		}
		var.nbp++;
		l++;
	}
	testeur_de_liste(var);
	var = resolution(var);
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
