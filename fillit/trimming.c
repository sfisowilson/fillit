#include "filler.h"
#include <stdlib.h>
#include <stdio.h>

void	trimming_x(f_list **node)
{
	int y;
	int x;
	int i;
	int j;

	y = (*node)->y_from;
	x = 0;
	while (((*node)->token[y][x] != '*') && ((*node)->token[y][x] != '\0'))
		x++;
	(*node)->x_from = x;
	(*node)->x_final = 0;
	i = 0;
	while (y < (*node)->token_y)
	{
		x = 0;
		i = 0;
		j = 0;
		while (x < (*node)->token_x)
		{
			if ((*node)->token[x][y] == '*')
			{
				j = (j == 0)? x : 0;
				i++;
			}
			x++;
		}
		(*node)->x_final = (i > (*node)->x_final)? i : (*node)->x_final;
		(*node)->x_from = (j < (*node)->x_from)? j : (*node)->x_from;
		fprintf(stderr, "x_from = %d, x_final = %d\n", (*node)->x_from, (*node)->x_final);
		y++;
	}
}

void	trimming_y(f_list **node)
{
	int y;

	y = 0;
	while (y < (*node)->token_y)
	{
		if (ft_strchr((*node)->token[y], '*'))
		{
			(*node)->y_from = y;
			(*node)->y_final = 0;
			while (ft_strchr((*node)->token[y++], '*'))
				(*node)->y_final++;
			break ;
		}
		else
			y++;
	}
	fprintf(stderr, "y from == %d, x from %d\n", (*node)->y_from, (*node)->x_from);
	trimming_x(node);
	fprintf(stderr, "y from == %d, x from %d\n", (*node)->y_from, (*node)->x_from);
	fprintf(stderr, "y final == %d, x final %d\n", (*node)->y_final, (*node)->x_final);
}
void			trimming(f_list **node)
{
	fprintf(stderr, "y from == %d, x from %d\n", (*node)->y_from, (*node)->x_from);
	trimming_y(node);
}
