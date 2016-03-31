/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:49:50 by zzeller           #+#    #+#             */
/*   Updated: 2016/03/29 21:37:12 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_var		valid(t_var var, char *tmp)
{
	int		i;
	int		d;
	int		dot;
	int		end;

	i = 0;
	d = 0;
	dot = 0;
	end = 0;
	var.link = 0;
	var.valid = 1;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '#')
		{
			if (tmp[i + 1] == '#')
				var.link++;
			if (tmp[i - 1] == '#')
				var.link++;
			if (tmp[i + 5] == '#')
				var.link++;
			if (tmp[i - 5] == '#')
				var.link++;
			d++;
		}
		else if (tmp[i] == '\n')
		{
			if (i % 5 == 4 || i == 20)
				end++;
			else
				var.valid = 0;
		}
		else if (tmp[i] == '.')
			dot++;
		else
			var.valid = 0;
		i++;
	}
	if (dot + d + end != 21 || d != 4 || end != 5 || var.link < 6)
		var.valid = 0;
	return (var);
}
