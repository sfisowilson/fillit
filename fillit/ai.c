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
			}
			x++;
		}
		y++;
	}
	return (1);
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
			}
			x--;
		}
		y++;
	}
	return (1);
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
			}
			x--;
		}
		y--;
	}
	return (1);
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
			}
			x++;
		}
		y--;
	}
	return (1);
}

int	ai(f_list **node)
{
	if ((*node)->calc == 0)
	{
		(aidl(node));
		(aidr(node));
		(aiur(node));
		(aiul(node));
		return (1);
	}
	else if((*node)->calc == 1)
	{
		(aiur(node));
		(aiul(node));
		(aidr(node));
		(aidl(node));
		return (1);
	}
	return (0);
}
