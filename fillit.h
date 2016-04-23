/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:16:51 by zzeller           #+#    #+#             */
/*   Updated: 2016/04/04 17:01:57 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			l;
	short			x[4];
	short			y[4];
	struct s_list	*next;
}					t_list;

typedef struct		s_var
{
	int				d;
	int				n;
	int				dot;
	short			index;
	short			end;
	char			l;
	int				fst;
	short			link;
	short			valid;
	short			nbp;
	short			size;
	short			solovarmax;
	short			solovar;
	t_list			*begin;
}					t_var;

void				ft_putchar(char c);
void				ft_putstr(char *str);
short				root(short i);
void				putmap(char *map, short solovarmax);
char				*printmap(char *map, t_list *list, short solovarmax, int i);
void				print_error(void);
t_var				right_position(t_var var, char *tmp, int i);
t_var				right_end(t_var var, int i);
void				usage(void);
t_var				ft_read(int fd, t_var var);
t_var				ft_read2(int fd, t_var var, char buf[22]);
t_var				valid(t_var var, char *tmp, int i);
t_list				*create_elem(char *tab);
char				*modif_line(char *tab);
char				*modif_column(char *tab);
char				*modif_all(char *tab);
t_list				*fillist(char *tmp, char l);
t_list				*call_fillist(t_list *list, char buf[22], t_var var);
short				place(short solovarmax, short i, t_list *list, char *map);
char				*rmtetri(char *map, t_list *list, short solovarmax, int i);
short				recusive(t_list *list, short solovarmax, short i,
					char *map);
char				*fildot(char *map, short solovarmax);
t_var				resolution(t_var var);
t_list				*list_xy(char *tab, t_list *list, int x, int y);
char				*modif_x(char *tab);
char				*modif_y(char *tab);

#endif
