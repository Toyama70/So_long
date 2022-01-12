/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:19 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/10 13:46:44 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_readmap(t_mapsize *mapsize, char *str)
{
	int		counter;
	int		fd;
	char	*line;

	counter = 0;
	line = "dummy";
	fd = open(str, O_RDONLY);
	while (line != 0)
	{
		line = get_next_line(fd);
		if (line != 0)
		{
			mapsize->l = ft_strlen(line) - 1;
			free(line);
			counter++;
		}
	}
	close(fd);
	return (counter);
}

char	**ft_parsemap(char *line, t_data *img, char *str, t_axis *axis)
{
	int			fd;
	char		**tab;
	t_mapsize	map;

	axis->i = -1;
	img->remain = 0;
	map.h = ft_readmap(&map, str);
	tab = ft_calloc(map.h + 1, sizeof(char *));
	while (++axis->i < map.h)
		tab[axis->i] = ft_calloc(map.l +1, 1);
	axis->i = -1;
	fd = open(str, O_RDWR);
	while (++axis->i < map.h)
	{
		axis->k = -1;
		line = get_next_line(fd);
		while (line[++axis->k] != 0 && line[axis->k] != '\n')
		{
			tab[axis->i][axis->k] = line[axis->k];
			if (line[axis->k] == 'C')
				img->remain += 1;
		}
		free(line);
	}
	return (tab);
}

t_mapsize	ft_setmap(char **tab)
{
	t_mapsize	map;

	map.h = 0;
	map.l = 0;
	while (tab[map.h] != 0)
	{
		while (tab[map.h][map.l] != 0)
		{
			map.l++;
		}
		map.h++;
	}
	return (map);
}
