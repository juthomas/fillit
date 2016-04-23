/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:32:46 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/04 17:04:42 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*call_fillist(t_list *list, char buf[22], t_var var)
{
	list->next = fillist(buf, var.l);
	list = list->next;
	return (list);
}

t_var	ft_read2(int fd, t_var var, char buf[22])
{
	int		i;

	i = 0;
	var.nbp++;
	var.l++;
	if (var.nbp > 26)
		print_error();
	var.index = read(fd, buf, 21);
	buf[var.index] = '\0';
	if (var.index == 20)
	{
		var.end = 1;
		buf[20] = '\n';
		buf[21] = '\0';
	}
	var = valid(var, buf, i);
	if (var.valid == 0)
		print_error();
	return (var);
}

t_var	ft_read(int fd, t_var var)
{
	char		buf[22];
	t_list		*list;

	var.end = 0;
	var.index = 1;
	var.l = 'A' - 1;
	var.fst = 1;
	while (var.index && var.end == 0)
	{
		var = ft_read2(fd, var, buf);
		if (var.fst)
			list = fillist(buf, var.l);
		else
			list = call_fillist(list, buf, var);
		if (var.fst)
		{
			var.fst = 0;
			var.begin = list;
		}
	}
	if (var.end == 0)
		return (var);
	var = resolution(var);
	return (var);
}

int		main(int argc, char **argv)
{
	t_var	var;
	int		fd;

	var.nbp = 0;
	var.link = 0;
	var.valid = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			print_error();
		var = ft_read(fd, var);
	}
	else
		usage();
	return (0);
}
