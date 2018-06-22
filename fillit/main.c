#include "filler.h"

int	main(void)
{
	f_list	*node;
	char	*line;

	node = (f_list*)malloc(sizeof(f_list));
	get_next_line(0, &line);
	if (get_players(&node, line))
		get_next_line(0, &line);
	if (get_mapsize(&node, line))
		get_next_line(0, &line);
	if (get_map(&node, line))
		get_next_line(0, &line);
	if (get_tokensize(&node, line))
		get_next_line(0, &line);
	if (get_token(&node, line))
		get_next_line(0, &line);
	if(ai(node))
		reply();
	else
		reply_end();
	return (0);
}
