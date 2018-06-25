#include "filler.h"
#include <stdlib.h>
#include <stdio.h>

void	trimming(f_list **node)
{
	int y;
	int x;
	(*node)->trim_y = 0;
	(*node)->trim_x = -1;

	y = 0;
	while (!(ft_strchr((*node)->token[y], '*')))
		y++;
	(*node)->trim_y = y;
	y = 0;
	while (y < (*node)->token_y)
	{
		x = 0;
		while (x < (*node)->token_x)
		{
			if (((*node)->trim_x == -1) && ((*node)->token[y][x] == '*'))
				(*node)->trim_x = x;
			else if (((*node)->trim_x > x) && ((*node)->token[y][x] == '*'))
				(*node)->trim_x = x;
			x++;
		}
		y++;
	}
	fprintf(stderr, "trim y = %d, trim x = %d\n", (*node)->trim_y, (*node)->trim_x);
}
