#include "filler.h"

int		aidr(f_list **node)
{
	int y;
	int x;

	y = 0;
	while ((*node)->map_y > y)
	{
		x = 0;
		while ((*node)->map_x > x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y;
				(*node)->play_x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		aidl(f_list **node)
{
	int y;
	int x;

	y = 0;
	while ((*node)->map_y > y)
	{
		x = (*node)->map_x;
		while (x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y;
				(*node)->play_x = x;
				return (1);
			}
			x--;
		}
		y++;
	}
	return (0);
}

int		aiul(f_list **node)
{
	int y;
	int x;

	y = (*node)->map_y;
	while (y)
	{
		x = (*node)->map_x;
		while (x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y;
				(*node)->play_x = x;
				//return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

int		aiur(f_list **node)
{
	int y;
	int x;

	y = (*node)->map_y;
	while (y)
	{
		x = 0;
		while (x < (*node)->map_x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y;
				(*node)->play_x = x;
				return (1);
			}
			x++;
		}
		y--;
	}
	return (0);
}

int	ai(f_list **node)
{
	if ((*node)->calc == 0)
		aiul(node);
	if ((*node)->calc == 1)
		aidr(node);
	if ((*node)->calc == 2)
		aidl(node);
	if ((*node)->calc == 3)
		aiur(node);
	return (1);
}
