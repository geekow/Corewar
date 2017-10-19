// HEADER //

# include "libft.h"

void		ft_free_gnl(int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
		ft_strdel(&line);
}
