#include "filler.h"

void	reply(f_list *node)
{
	ft_putnbr(node->user_pos_y);
	ft_putchar(' ');
	ft_putnbr(node->user_pos_x);
	ft_putchar('\n');
}
