/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:56:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/06 14:47:19 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int		deal_key(int key, void *param)
{

	write(1, "x", 1);

	return (0);
}
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

void	ft_fillrock(t_data *img, t_rock *rock, char *file)
{
	rock->img = mlx_xpm_file_to_image(img->mlx, file, &rock->w, &rock->h);

	rock->addr = mlx_get_data_addr(rock->img, &rock->bpp, &rock->l_l, &rock->endian);


}

void	ft_fillcoll(t_data *img, t_coll *coll, char *file)
{
	coll->img = mlx_xpm_file_to_image(img->mlx, file, &coll->w, &coll->h);

	coll->addr = mlx_get_data_addr(coll->img, &coll->bpp, &coll->l_l, &coll->endian);

}

void	ft_filldoor(t_data *img, t_door *door, char *file)
{
	door->img = mlx_xpm_file_to_image(img->mlx, file, &door->w, &door->h);

	door->addr = mlx_get_data_addr(door->img, &door->bpp, &door->l_l, &door->endian);

}

void	render_back(t_data *img, t_mapsize M)
{
	int	i;	
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, k * 64, i *64);
			k++;
		}
		i++;
	}
}

void	render_rock(t_data *img, t_mapsize M, char **tab)
{

	int	i;	
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->rock.img, k * 64, i *64);
			k++;
		}
		i++;
	}
}


void	render_hero(t_data *img, t_mapsize M, char **tab)
{

	int	i;	
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == 'P')
				mlx_put_image_to_window(img->mlx, img->win, img->her.img, 64 * k, 64 * i);
			k++;
		}
		i++;
	}
}


void	render_coll(t_data *img, t_mapsize M, char **tab)
{
	int	i;	
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == 'C')
				mlx_put_image_to_window(img->mlx, img->win, img->coll.img, 64 * k, 64 * i);
			k++;
		}
		i++;
	}
}

void	render_door(t_data *img, t_mapsize M, char **tab)
{
	int	i;	
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == 'E')
				mlx_put_image_to_window(img->mlx, img->win, img->door.img, 64 * k, 64 * i);
			k++;
		}
		i++;
	}
}

void	ft_storeimages(t_data *img, t_hero hero, t_txtr txtr, t_rock rock)
{
	img->her = hero;
	img->txtr = txtr;
	img->rock = rock;
}

void	ft_storeimages2(t_data *img, t_coll coll, t_door door)
{
	img->door = door;
	img->coll = coll;
}

void	ft_renderer(t_data *img, t_mapsize M, char **tab)
{

	render_back(img, M);
	render_rock(img, M, tab);
	render_hero(img, M, tab);
	render_coll(img, M, tab);
	render_door(img, M, tab);
}

void	ft_matrix(t_data *img, t_mapsize M, char **tab)
{
	t_hero hero;
	t_txtr txtr;
	t_rock rock;
	t_coll coll;
	t_door door;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, M.L * 64, M.H * 64, "So_long");
		
	mlx_key_hook(img->win, deal_key, (void *)0); 

	ft_fillhero(img, &hero, "rsrcs/hero.xpm");
	ft_fillback(img, &txtr, "rsrcs/ground.xpm");
	ft_fillrock(img, &rock, "rsrcs/rock.xpm");
	ft_fillcoll(img, &coll, "rsrcs/coll.xpm");
	ft_filldoor(img, &door, "rsrcs/door.xpm");
	ft_storeimages(img, hero, txtr, rock);
	ft_storeimages2(img, coll, door);
	ft_renderer(img, M, tab);
	
//	mlx_loop(img->mlx);

}
