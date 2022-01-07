/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:04:15 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/07 17:43:56 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int main(int argc, char *argv[])
{
	char *line;
	char **tab;
	t_mapsize map;
	t_data img;

	tab = ft_parsemap(line, &img);
	map = ft_setmap(tab);
	printf("h  = %d and  l=%d \n", map.H, map.L);
	
	img.points = tab;
	printf("number of collectibles at start : %d\n", img.remain);
	ft_matrix(&img, map, tab);
	mlx_key_hook(img.win, deal_key, &img);
	mlx_loop(img.mlx);


	free_tab(tab);//Ce free s'applique aussi a img.points en fait.s
//	system("leaks a.out");
}
