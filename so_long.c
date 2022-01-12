/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:56:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/10 13:45:21 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_storeimages(t_data *img, t_comp hero, t_comp txtr, t_comp rock)
{
	img->her = hero;
	img->txtr = txtr;
	img->rock = rock;
}

void	ft_storeimages2(t_data *img, t_comp coll, t_comp door)
{
	img->door = door;
	img->coll = coll;
}

void	ft_matrix(t_data *img, t_mapsize M, char **tab)
{
	t_comp	hero;
	t_comp	txtr;
	t_comp	rock;
	t_comp	coll;
	t_comp	door;

	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, M.l * 64, M.h * 64, "So_long");
	ft_fillhero(img, &hero, "rsrcs/hero.xpm");
	ft_fillback(img, &txtr, "rsrcs/ground.xpm");
	ft_fillrock(img, &rock, "rsrcs/rock.xpm");
	ft_fillcoll(img, &coll, "rsrcs/coll.xpm");
	ft_filldoor(img, &door, "rsrcs/door.xpm");
	ft_storeimages(img, hero, txtr, rock);
	ft_storeimages2(img, coll, door);
	ft_renderer(img, M, tab);
}
