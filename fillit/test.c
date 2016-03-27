#include "fillit.h"



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


int	main(int argc, char **argv)
{
	char *tab;
	t_list *list;

	tab = (char*)malloc(sizeof(argv[1]));
	tab = argv[1];
	tab = modifall(tab);
	list = takexy(tab);
	int i ;
	i = 0;
	while (i < 4)
	{
		printf("x%d: %d\ny%d: %d\n",i, list->xt[i],i, list->yt[i]);
		i++;
	}
	//					tab = modiftabline(tab);
	//					tab = modiftabline(tab);

	printf("%s", tab);
}

