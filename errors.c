/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:49:50 by zzeller           #+#    #+#             */
/*   Updated: 2016/04/04 17:00:52 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_var		right_position(t_var var, char *tmp, int i)
{
	if (tmp[i + 1] == '#')
		var.link++;
	if (tmp[i - 1] == '#')
		var.link++;
	if (tmp[i + 5] == '#')
		var.link++;
	if (tmp[i - 5] == '#')
		var.link++;
	var.d++;
	return (var);
}

t_var		right_end(t_var var, int i)
{
	if (i % 5 == 4 || i == 20)
		var.n++;
	else
		var.valid = 0;
	return (var);
}

t_var		valid(t_var var, char *tmp, int i)
{
	var.n = 0;
	var.dot = 0;
	var.d = 0;
	var.link = 0;
	var.valid = 1;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '#')
			var = right_position(var, tmp, i);
		else if (tmp[i] == '\n')
			var = right_end(var, i);
		else if (tmp[i] == '.')
			var.dot++;
		else
			var.valid = 0;
		i++;
	}
	if (var.dot + var.d + var.n != 21 || var.d != 4 || var.n != 5
			|| var.link < 6)
		var.valid = 0;
	return (var);
}

void		print_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void		usage(void)
{
	ft_putstr("usage: ./fillit [-FILE]\n");
	exit(EXIT_FAILURE);
}
