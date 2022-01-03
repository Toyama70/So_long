/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:19 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/03 16:22:55 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h" 


//void ft_parse(char *str);

//char	*

void free_tab(char **tab)
{
	size_t i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	ft_readmap(int *length)
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
		printf("%s", line);
		if (line != 0)
		{
			free(line);
			*length = strlen(line) - 1;
			counter++;
		}
	}
	printf("%d\n", counter);
	close(fd);
	return (counter);

}

int main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	char	**result;
	int		counter;
	int		length;

	line = "dummy";
	//result[0] = 0;
	counter = ft_readmap(&length);  //can retrieve all required infos
	//system("leaks a.out");

	fd = open("testmap.ber", O_RDONLY);

	while (line != 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	printf("length = %d\n", length);

	close(fd);
//	system("leaks a.out");
}
