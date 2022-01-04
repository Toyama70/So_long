/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:19 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/04 17:23:03 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h" 

typedef struct s_mapsize {
	int	length;
	int	height;
}	t_mapsize;



void free_tab(char **tab)
{
	size_t i;

	i = -1;
	while (++i < 6)
		free(tab[i]);
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
			free(line);
			mapsize->length = strlen(line) - 1;
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

	tab = calloc(500, sizeof(char)); // THIS WAS THE CAUSE OF THE PROBLEM, I NEED TO CHECK WHY
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
		printf("line : %s\n", line);
		printf("i = %d\n", i);
		
		while (line[k] != 0 && line[k] != '\n')
		{
			tab[i][k] = line[k];
			k++;
		}
		free(line);
		i++;
	}

		printf("tab[0] : %s\n", tab[0]);
		printf("tab[1] : %s\n", tab[1]);
		printf("tab[2] : %s\n", tab[2]);
		printf("tab[3] : %s\n", tab[3]);
		printf("tab[4] : %s\n", tab[4]);
	/*printf("ok\n");
	free(tab[0]);
	printf("ok\n");
	free(tab[1]);
	printf("ok\n");
	free(tab[2]);
	printf("ok\n");
	free(tab[3]);
	printf("ok\n");
	free(tab[4]);
	printf("ok\n");*/
//	free(tab); //FIRST LEAK IS THIS ONE
//	free(tab[5]);
//	system("leaks a.out");

	return (tab);
}

int main(int argc, char *argv[])
{
	char *line;
	char **tab;
	tab = ft_parsemap(line);
//	tab[0] = "hello";

	printf("result[0] = %s\n", tab[0]);
	printf("result[1] = %s\n", tab[1]);
	printf("result[2] = %s\n", tab[2]);
	printf("result[3] = %s\n", tab[3]);
	printf("result[4] = %s\n", tab[4]);
/*	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
	free(tab[4]);
*/	free_tab(tab);
	system("leaks a.out");
}
