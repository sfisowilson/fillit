#include "filler.h"
#include <stdlib.h>

char	*get_map(f_list **node, char *line)
{
	int i;
	int	len;
	int	j;
	
	fprintf(stderr, "first line in get map == %s\n", line);
	i = 0;
	if ((line)[0] == ' ')
		get_next_line(0, &line);
	len = ft_strlen(line) - 4;
	(*node)->map  = (char **)malloc(sizeof(char *) * (*node)->map_y);
	while ((*node)->map_y > i)
	{
		(*node)->map[i] = ft_strsub((line) + 4, 0, len);
		if (ft_strchr((*node)->map[i], (*node)->user))
		{
			j = 0;
			while ((*node)->map[i][j] != (*node)->user)
				j++;
			(*node)->user_pos_y = i;
			(*node)->user_pos_x = j;
		}

		fprintf(stderr, "%i line added to map == %s\n", i, (*node)->map[i]);
		get_next_line(0, &line);
		i++;
	}
	fprintf(stderr, "line returned from  map == %s\n", line);
	return (line);
}
