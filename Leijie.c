/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Leijie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:19 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/04 16:32:36 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h" 
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;
	size_t			k;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		dest = malloc(sizeof(char) * 1);
	else if (ft_strlen(s) - start < len)
		dest = malloc(sizeof(char) * ft_strlen(s) - start + 1);
	else
		dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = start;
	k = 0;
	while (i < len + start && start < ft_strlen(s))
	{
		dest[k] = s[i];
		i++;
		k++;
	}
	dest[k] = 0;
	return (dest);
}
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

char **ft_parsemap(char *line) //will need argc argv
{
	int		fd;
	char *joined;
	char	**tab;
	t_mapsize map;
	int i = -1;
	
	map.height = ft_readmap(&map);

printf("mapheight = %d\n", map.height);
	tab = calloc(sizeof(char), map.height);
/*	while (++i < map.height)
	{
		tab[i] = calloc(map.length +1, 1);
		printf("i = %d\n", i);
	}*/
	i = 0;
	fd = open("testmap.ber", O_RDONLY);
//	line = calloc(map.length + 1, 1);

	while (i < map.height)
	{
		line = get_next_line(fd);
		tab[i] = ft_substr(line, 0, ft_strlen(line));
		//strcpy(tab[1] ,line);
		printf("line : %s\n", line);
//		printf("tab[%d] : %s", i, line);
		free(line);
		i++;
	}
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
//	free(result[0]);
//	free(result[1]);
//	free(result[2]);
//	free(result[3]);
//	free(result[4]);
	system("leaks a.out");
}
