#include "game.h"

void		check_size(t_env *env)
{
	if (COLS < 21 || LINES < 10)
	{
		while (COLS < 21 || LINES < 10)
		{
			clear();
			mvprintw(0, 0, "Insufisant win size");
			refresh();
			usleep(50000);
		}
	}
}
