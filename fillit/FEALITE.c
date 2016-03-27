/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FEALITE.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 16:09:34 by zzeller           #+#    #+#             */
/*   Updated: 2016/03/26 16:09:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_list_push_back(t_list **begin_list, t_var var)
{
	t_list  *list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem();
	}
	else
		*begin_list = ft_create_elem();
}

t_list	*ft_create_elem(void)
{
	t_list		*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->next = NULL;
	}
	return (tmp);
}

t_var			valid_list(t_var var)
{
	int		i;
	int		x;
	int		y;
	int		d;
	short int	*deja;

	i = 0;
	x = 0;
	y = 0;
	d = 0;
	var.h = 1;
	var.w = 1;
	deja = (short int*)malloc(sizeof(short int) * 22);
	var.valid = 1;
	while (i < 22)
	{
		var.tab[i] = -1;
		i++;
	}
	i = 0;
	while (var.tmp[i] != '\0')
	{
			ft_putstr("ok\n");
		if (var.tmp[i] == '#' || var.tmp[i] == '.' || var.tmp[i] == '\n')
		{
			if (var.tmp[i] == '#')
			{
				if (deja[i] == 1 && d == 3)
					;
				else if (var.tmp[i + 1] == '#' && var.tab[i + 1] == -1
						&& (i + 1) % 5 != 4)
				{
					deja[i + 1] = 1;
					var.tab[i + 1] = i;
					var.tab[i] = i + 1;
					var.w++;
				}
				else if (var.tmp[i - 5] == '#' && var.tab[i - 5] == -1
						&& (i >= 0))
				{
					deja[i - 5] = 1;
					var.tab[i - 5] = i;
					var.tab[i] = i - 5;
					var.h++;
				}
				else if (var.tmp[i - 1] == '#' && var.tab[i - 1] == -1
						&& (i - 1) % 5 != -1)
				{
					deja[i - 1] = 1;
					var.tab[i - 1] = i;
					var.tab[i] = i - 1;
					var.w++;
				}
				else if (var.tmp[i + 5] == '#' && var.tab[i + 5] == -1
						&& (i + 5) / 5 != 4)
				{
					deja[i + 5] = 1;
					var.tab[i + 5] = i;
					var.tab[i] = i + 5;
					var.h++;
				}
				else
					var.valid = 0;
				d++;
			}
			else if (var.tmp[i] == '\n')
			{
				if (i % 5 != 4)
				{
					if (i % 5 != 0 || i / 5 != 5)
						var.valid = 0;
				}
				y++;
				x = 0;
			}
			else
				x++;
			if (d > 4)
				var.valid = 0;
		}
	}
	if (d != 4)
		var.valid = 0;
	return(var);
}
/*
t_var	pick_num(t_var var, char tmp[22])
{
	short unsigned int	i;
	short unsigned int	x;
	short unsigned int	y;
	short unsigned int	tetrinu;

	tetrinu = 0;
	x = 0;
	y = 0;
	i = 0;
	while (i < 22)
	{
		if (tmp[i] == '#')
		{
			var.tmpx[tetrinu] = x;
			var.tmpy[tetrinu++] = y;
		}
		if (tmp[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
			x++;
		i++;
	}
	return (var);
}
*/
t_var	epur(t_var var)
{
	short int	i;
	short int	d;

	i = 0;
	d = 4;
	while (i < 21)
	{
		while (d != 0)
		{
		
		}
	}
	return (var);
}

char	*modiftabcolumn(char *tab)
{
	int	i;

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



char	*modiftabline(char *tab)
{
	int	i;

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

char *modifall(char *tab)
{
	short int i;
	short int x;
	short int y;
	short int ok;

	ok = 0;
	i = 0;
	x = 0;
	y = 0;

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
			tab = modiftabline(tab);
			i = 0;
		}
		}

	ok = 0;
	i = 0;
	while (i < 21 && ok == 0)
	{
		if (i % 5 == 0)
		{
			if (tab[i] == '#')
				ok = 1;
		}
		if (i == 20)
		{
			tab = modiftabcolumn(tab);
			i = -1;
		}
		i++;
	}



	


	return (tab);

}

t_list	*takexy(char *tab)
{
	int		x;
	int		y;
	int		i;
	int		t;
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	list->xt = (short int*)malloc(sizeof(short int) * 4);
	list->yt = (short int*)malloc(sizeof(short int) * 4);

	x = 0;
	y = 0;
	i = 0;
	t = 0;
	while (i < 21)
	{
		if (tab[i] == '#')
		{
			list->xt[t] = x;
			list->yt[t] = y;
			t++;
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


t_var	fillist(char *tmp, t_var var)
{

//	ou = y;
	var.tmp = tmp;
			ft_putstr("ok\n");
var = valid_list(var);

		ft_putstr("ok\n");
//	if (var.valid == 0)
//		ERROR;
//	var = pick_num(var, tmp);
	var.list = takexy(tmp);
	var.nbp++;
	return (var);
}







t_var	in_list(int argc, char **argv, t_var var)
{
	int			fd;
	char		*tmp;
	short int	tru;
	char		l;

			ft_putstr("ok\n");

	tmp = (char *)malloc(sizeof(char) * 22);
//	var = (t_var)malloc(sizeof(t_var));
	l = 'A';
	tmp[21] = '\0';
	fd = open(argv[1], O_RDONLY);
	tru = read(fd, tmp, 21);
				ft_putstr("ok\n");
//	var.list = (var.list)malloc(sizeof(var.list));
//	var.list = *var.beg;
			ft_putstr("ok\n");
	while (tru && l <= 'Z')
	{
		ft_putstr("ok\n");
		var = fillist(tmp, var);
	
			ft_putstr("ok\n");
	var.list->l = l;
		l++;
		tru = read(fd, tmp, 21);
		var.list->next = ft_create_elem();
		var.list = var.list->next;
		printf("ok\n");
	}
	return (var);
}

int		main(int argc, char **argv)
{
	t_var	var;

	var = in_list(argc, argv, var);





}


