#include "game.h"

void		check_size(t_env *env)
{
	if (COLS < 11 || LINES < 41)
	{
		while (LINES < 17 || LINES < 41)
		{
			clear();
			mvprintw(0, 0, "Insufisant win size");
			refresh();
			sleep(1);
		}
	}
}
