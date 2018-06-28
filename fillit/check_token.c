#include "filler.h"
#include <stdlib.h>

int	check_token(f_list **node, int my, int mx)
{
	//fprintf(stderr, "check token ===  y = %i, x = %i\n", my, mx);
	int	y;
	int	x;
	int	shell_try;
	
	y = 0;
	shell_try = 0;
	while ((*node)->token_y > y)
	{
		x = 0;
		while ((*node)->token_x > x)
		{
			if ((((*node)->map[my + y][mx + x] == (*node)->user) ||\
				(*node)->map[my + y][mx + x] == (*node)->user + 32) &&\
				((*node)->ttoken[y][x] == '*'))
				shell_try++;
			if ((((*node)->map[my + y][mx + x] == (*node)->opp) ||\
				(*node)->map[my + y][mx +  x] == (*node)->opp + 32) &&\
				((*node)->ttoken[y][x] == '*'))
				return (0);
			x++;
		}
		y++;
	}
	/*fprintf(stderr, "shell_try = %i\n", shell_try);
	if (shell_try == 1)
	{
		fprintf(stderr, "returning 1, my = %i, mx = %i\n", my, mx);
		fprintf(stderr, "returning 1, y = %i, x = %i\n", y, x);
	}*/
	return ((shell_try == 1)? 1 : 0);
}
