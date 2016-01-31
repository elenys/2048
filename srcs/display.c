# include "game.h"


static void		print_v_line()
{
	int i;
	int width;
	int hight;

	i = 0;
	width = COLS / 4;
	if (COLS % 4 == 0)
		width -= 1;
	hight = (LINES / 4) * 4;
	if (LINES % 4 == 0)
		hight -= 4;
	while (i <= 4)
	{
		mvvline(0, width * i, 0, hight);
		i++;
	}
	refresh();
}

static void		print_h_line()
{
	int i;
	int width;
	int hight;

	i = 0;
	hight = LINES / 4;
	if (LINES % 4 == 0)
		hight -= 1;
	width = (COLS / 4) * 4;
	if (COLS % 4 == 0)
		width -= 3;
	else
		width += 1;
	while (i <= 4)
	{
		mvhline(i * hight, 0, 0, width);
		i++;
	}
	refresh();
}

static int		size_nb(int nb)
{
	return (ft_strlen(ft_itoa(nb)) / 2);
}

static void		print_value(int **tab)
{
	int i;
	int j;
	int width;
	int hight;

	i = 0;
	hight = LINES / 4;
	if (LINES % 4 == 0)
		hight -= 1;
	width = (COLS / 4);
	if (COLS % 4 == 0)
		width -= 1;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mvprintw(hight * i + LINES / 8, width * j  + 1 + COLS / 8 -
				size_nb(tab[i][j]) , "%d", tab[i][j]);
			j++;
		}
		i++;
	}
	refresh();
}

void		print_board(t_env *env)
{
	clear();
	print_value(env->board);
	print_v_line();
	print_h_line();
	refresh();
}
