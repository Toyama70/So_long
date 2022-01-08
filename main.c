/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:04:15 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/08 15:24:40 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	mouse_hook(t_data *img)
{
	free_tab(img->points);
	exit(0);
	return (1);
}

int main(int argc, char *argv[])
{
	char *line;
	char **tab;
	t_mapsize map;
	t_data img;

	ft_errorhandler1(argc, argv);
	img.movecount = 0;
	tab = ft_parsemap(line, &img, argv[1]);
	map = ft_setmap(tab);
	printf("h  = %d and  l=%d \n", map.H, map.L);
	img.points = tab;
	ft_errorhandler2(&img, &map);
	printf("number of collectibles at start : %d\n", img.remain);
	ft_matrix(&img, map, tab);
	mlx_key_hook(img.win, deal_key, &img);
	mlx_hook(img.win, 17, 1L << 2, mouse_hook, &img);
	mlx_loop(img.mlx);


	free_tab(tab);//Ce free s'applique aussi a img.points en fait
//	system("leaks a.out");
}
