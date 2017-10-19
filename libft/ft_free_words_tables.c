// HEADER //

# include "libft.h"

void		ft_free_words_tables(char ***tab)
{
	char	**target;
	int		i;

	i = -1;
	target = *tab;
	while (target[++i])
		ft_strdel(&(target[i]));
	free(target);
}
