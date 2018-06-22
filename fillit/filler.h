#ifndef FILLER_H
# define FILLER_H
# include "get_next_line.h"
typedef struct 		f_list
{
	char		**map;
	char		**token;
	char		user;
	char		opp;
	int		map_y;
	int		map_x;
	int		token_y;
	int		token_x;
	int		user_pos_y;
	int		user_pos_x;
	int		play_y;
	int		play_x;
}			f_list;
int	get_players(f_list **node, char *line);
int	get_mapsize(f_list **node, char *line);
int	get_tokensize(f_list **node, char *line);
int	get_map(f_list **node, char *line);
int	get_token(f_list **node, char *line);
int	ai(f_list *node);
void	reply(void);
void	reply_end(void);
#endif
