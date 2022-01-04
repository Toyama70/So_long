/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:20:32 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/04 16:14:43 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "so_long.h"

int main()
{

	int fd;
	char *line;

	fd = open("testmap.ber", O_RDONLY);
	line = "placeholder";
	while(line != 0)
	{
		line = get_next_line(fd);
		printf("line = %s\n", line);
		free(line);
	}
	system("leaks a.out");
}
