/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:19 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/05 15:29:13 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_readmap(t_mapsize *mapsize)
{
	int		counter;
	int		fd;
	char	*line;

	counter = 0;
	line = "dummy";
//	ft_parse(argv[1]);
	fd = open("testmap.ber", O_RDONLY);

	while (line != 0)
	{
		line = get_next_line(fd);
		if (line != 0)
		{
			mapsize->length = strlen(line) - 1;
			free(line);
			counter++;
		}
	}
	close(fd);
	return (counter);

}

char **ft_parsemap(char *line) //will need argc argv
{
	int		fd;
	char	**tab;
	t_mapsize map;
	int i = 0;

	map.height = ft_readmap(&map);
	tab = calloc(map.height, sizeof(char *));
	while (i < map.height)
	{
		tab[i] = calloc(map.length +1, 1);
		i++;
	}
	i = 0;
	fd = open("testmap.ber", O_RDWR);
//	line = calloc(map.length + 1, 1);

	int k = 0;
	int m = 0;

	while (i < map.height)
	{
		k = 0;
		line = get_next_line(fd);

		while (line[k] != 0 && line[k] != '\n')
		{
			tab[i][k] = line[k];
			k++;
		}
		free(line);
		i++;
	}
	return (tab);
}

void	ft_setmap(char **tab)
{
//handles  trees walls amd textures;
	t_mapsize map;	
	map.height = 0;
	map.length = 0;

	while (tab[map.height] != 0)
	{
		printf("i = %d\n", map.height);
		while (tab[map.height][map.length] != 0)
		{
			printf("k = %d\n", map.length);
			map.length++	;
		}
		map.height++;
	}






}

int main(int argc, char *argv[])
{
	char *line;
	char **tab;
	tab = ft_parsemap(line);
	ft_setmap(tab);
	t_data img;

	ft_matrix(&img);





	mlx_loop(img.mlx);










	free_tab(tab);//Ce free peut etre transpose ailleurs

	system("leaks a.out");
}
