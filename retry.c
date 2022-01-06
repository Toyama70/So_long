/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:19 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/06 14:36:44 by ybestrio         ###   ########.fr       */
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
			mapsize->L = strlen(line) - 1;
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

	map.H = ft_readmap(&map);
	tab = calloc(map.H + 1, sizeof(char *));
	while (i < map.H)
	{
		tab[i] = calloc(map.L +1, 1);
		i++;
	}
	i = 0;
	fd = open("testmap.ber", O_RDWR);

	int k = 0;
	int m = 0;

	while (i < map.H)
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

t_mapsize	ft_setmap(char **tab)
{
	t_mapsize map;	
	map.H = 0;
	map.L = 0;

	while (tab[map.H] != 0)
	{
		printf("i = %d\n", map.H);
		while (tab[map.H][map.L] != 0)
		{
			printf("k = %d\n", map.L);
			map.L++	;
		}
		map.H++;
	}
return (map);
}

int main(int argc, char *argv[])
{
	char *line;
	char **tab;
	t_mapsize map;
	t_data img;
	tab = ft_parsemap(line);
	map = ft_setmap(tab);
	printf("h  = %d and  l=%d \n", map.H, map.L);
	ft_matrix(&img, map, tab);

	mlx_loop(img.mlx);


	free_tab(tab);//Ce free peut etre transpose ailleurs

//	system("leaks a.out");
}
