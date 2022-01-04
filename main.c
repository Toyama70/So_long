/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:19 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/04 14:38:22 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h" 

typedef struct s_mapsize {
	int	length;
	int	height;
}	t_mapsize;

//void ft_parse(char *str);

//char	*

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

void ft_strcopy(char **line)
{
	int fd;

	fd = open("testmap.ber", O_RDONLY);

	*line = get_next_line(fd);

}

char **ft_create_tab(char **tab, t_mapsize map)
{
	char *line;
	int i;
//	line = calloc(20, 1);
	line = "placeholder";
	//line = malloc(sizeof(char) * map->length);
	i = 0;
	while (i < map.height)
	{
		ft_strcopy(&line);
		printf("line = %s\n", line);
		tab[i] = line;
		i++;
	}
	return (tab);


}

char **ft_parsemap() //will need argc argv
{
	int		fd;
	char	**tab;
	t_mapsize map;
	
	map.height = ft_readmap(&map);  
	fd = open("testmap.ber", O_RDONLY);
	tab = malloc(map.height + 1 * sizeof(char));
	tab = ft_create_tab(tab, map);
	//tab[0] = "yahooo";
	printf("tab[0] = %s\n", tab[0]);
	return (tab);
}

int main(int argc, char *argv[])
{
	char **tab;

	tab = ft_parsemap();
//	tab[0] = "hello";
	printf("result[0] = %s\n", tab[0]);
	printf("result[1] = %s\n", tab[1]);
	printf("result[2] = %s\n", tab[2]);
	printf("result[3] = %s\n", tab[3]);
	printf("result[4] = %s\n", tab[4]);
//	free(result[0]);
//	free(result[1]);
//	free(result[2]);
//	free(result[3]);
//	free(result[4]);
	system("leaks a.out");
}
