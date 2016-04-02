/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:32:46 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/02 18:24:57 by juthomas         ###   ########.fr       */
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

short	place(short solovarmax, short i, t_list *list, char *map)
{
	short	x;
	short	u;

	u = 0;
	x = root(solovarmax);
	while (u < 4)
	{
		if (map[(i % x + list->x[u]) + (list->y[u] * x + i / x)] != '.')
			return(0);
		if (i % x + list->x[u] > x)
			return (0);
		if (i / x + list->y[u] > x)
			return (0);
		u++;
	}
	return (1);
}

char	*printmap(char *map, t_list *list, short solovarmax, int i)
{
	short	u;
	short	x;

	x = root(solovarmax);
	u = 0;
	while (u < 4)
	{
		map[(i % x + list->x[u]) + (list->y[u] * x + i / x)] = list->l;
		u++;
	}


	return (map);
}

short	recusivpowa(t_list *list, short solovarmax, short i, char *map)
{
	putmap(map, solovarmax);
	while (i < solovarmax)
	{
		if (!list)
		{
			putmap(map, solovarmax);
			return (1);
		}
		if (place(solovarmax, i, list, map) == 1)
		{
			map = printmap(map, list, solovarmax, i);
			recusivpowa(list->next, solovarmax, 0, map);
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
	printf("size :%d\n", var.size);
	printf("solovar :%d\n", var.solovarmax);
	var.solovar = 0; //evite d'avoir x et y qui seront trouvables
	// par n % 5 et n / 5 (d'ou le nom solovarmax) 

	while (var.solovarmax <= 196)
	{
		map = (char*)malloc(sizeof(char) * var.solovarmax);
		map[var.solovarmax] = '\0';
		map = fildot(map, var.solovarmax);
		if (recusivpowa(list, var.solovarmax, 0, map) == 1)
			return (var);
		free(map);
		var.solovarmax = ++var.size * var.size;
		printf("value solovar :%d\n", var.solovarmax);
	}
	return (var);
}

void	testeur_de_liste(t_var var)
{
	t_list *list;

	list = var.begin;
	int k = 0;
	int m = 0;
	while (list)
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
	while (list)
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
	short		end;

	end = 0;
	index = 1;
	l = 'A' - 1;
	fd = open(argv[1], O_RDONLY);
	while (index && end == 0)
	{
		var.nbp++;
		l++;
		if (var.nbp > 26)
			return (var);
		index = read(fd, buf, 21);
		buf[index] = '\0';
		printf("index : %d\n", index);
		if (index == 20)
		{
			end = 1;
			buf[20] = '\n';
			buf[21] = '\0';
		}
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

	}
	if (end == 0)
		return (var);
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
