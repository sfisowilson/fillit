#include "filler.h"
#include <stdlib.h>

int	main(void)
{
	f_list	*node;
	char	*line;

	node = (f_list*)malloc(sizeof(f_list));
	get_next_line(0, &line);
	fprintf(stderr,"the first line = %s\n", line);
	if (get_players(&node, line))
		get_next_line(0, &line);
	node->opp = (node->user == 'O')? 'X' : 'O';
	fprintf(stderr,"My user character = %c\n", node->user);
	fprintf(stderr,"the opp  character = %c\n", node->opp);
	if (get_mapsize(&node, line))
		get_next_line(0, &line);
	fprintf(stderr,"map size y = %i\n", node->map_y);
	fprintf(stderr,"map size x = %i\n", node->map_x);
	// MAP
	line = get_map(&node, line);
	// TOKEN SIZE
	get_tokensize(&node, line);
	fprintf(stderr,"token size y = %i\n", node->token_y);
	fprintf(stderr,"token size x = %i\n", node->token_x);
	
	fprintf(stderr,"user pos y = %i\n", node->user_pos_y);
	fprintf(stderr,"user pos x = %i\n", node->user_pos_x);

	get_next_line(0, &line);
	
	line = get_token(&node, line);

	if(ai())
		reply(node);
	else
		reply_end();
	return (0);
}
