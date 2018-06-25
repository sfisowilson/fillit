#include "filler.h"

void	reply(f_list **node)
{
	ft_putnbr((*node)->play_y);
	ft_putchar(' ');
	ft_putnbr((*node)->play_x);
	ft_putchar('\n');
	freeit(node);
}
