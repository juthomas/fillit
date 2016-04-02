#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_list
{
	char			l;
	short			x[4];
	short			y[4];
	struct s_list	*next;
}					t_list;

typedef struct		s_var
{
	short			link;
	short			valid;
	short			nbp;
	short			size;
	short			solovarmax;
	short			solovar;
	t_list			*begin;
}					t_var;

t_var				ft_read(char **argv, t_var var);
t_var				valid(t_var var, char *tmp);
t_list				*create_elem(char *tab);
char				*modif_line(char *tab);
char				*modif_column(char *tab);
char				*modif_all(char *tab);
t_list				*fillist(char *tmp, char l);

#endif
