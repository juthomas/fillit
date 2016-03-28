#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_list
{
	char		l;
	short int	*xt;
	struct s_list	*next;
	short int	*yt;
}					t_list;

typedef struct		s_var
{
	short int		link;
	short int		h;
	short int		valid;
	short int		tab[22];
	char			**grill;
	short int		nbp;
	t_list			**beg;
	t_list			*list;
	size_t			size;
	int				i;
	char			*str;
	char			*tmp;
	short int		tmpx[4];
	short int		tmpy[4];
}					t_var;

t_list	*ft_create_elem(void);
void	ft_list_push_back(t_list **begin_list, t_var var);
t_var		algo(t_var var);
#endif
