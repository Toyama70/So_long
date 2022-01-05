/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:56:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/05 16:43:32 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int		deal_key(int key, void *param)
{

	write(1, "x", 1);

	return (0);
}*/
void	ft_fillhero(t_data *img, t_hero *hero, char *file)
{

	hero->img = mlx_xpm_file_to_image(img->mlx, file, &hero->w, &hero->h);

	hero->addr = mlx_get_data_addr(hero->img, &hero->bpp, &hero->l_l, &hero->endian);


}

void	ft_fillback(t_data *img, t_txtr *txtr, char *file)
{

	txtr->img = mlx_xpm_file_to_image(img->mlx, file, &txtr->w, &txtr->h);

	txtr->addr = mlx_get_data_addr(txtr->img, &txtr->bpp, &txtr->l_l, &txtr->endian);


}

void	ft_matrix(t_data *img)
{
	t_hero hero;
	t_txtr txtr;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1280, 720, "So_long");
//	mlx_pixel_put(img->mlx, img->win, 5, 5, 0x00FF0000);

		
	//mlx_key_hook(img->win, deal_key, (void *)0); 

	ft_fillhero(img, &hero, "hero.xpm");
	ft_fillback(img, &txtr, "ground.xpm");
	img->her = hero;
	img->txtr = txtr;
//	ft_output()//output image	

int i = -1;
	while(++i < 12)
		mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, i * 64, 0);
	
	
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, 0, 0)	;
	
	
	
	
	
//	mlx_loop(img->mlx);

}
