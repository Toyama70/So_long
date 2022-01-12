/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datafiller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:58:25 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/10 11:45:41 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_fillhero(t_data *img, t_comp *hero, char *file)
{
	hero->img = mlx_xpm_file_to_image(img->mlx, file, &hero->w, &hero->h);
	hero->addr = mlx_get_data_addr(hero->img, &hero->bpp, &hero->l_l,
			&hero->endian);
}

void	ft_fillback(t_data *img, t_comp *txtr, char *file)
{
	txtr->img = mlx_xpm_file_to_image(img->mlx, file, &txtr->w, &txtr->h);
	txtr->addr = mlx_get_data_addr(txtr->img, &txtr->bpp, &txtr->l_l,
			&txtr->endian);
}

void	ft_fillrock(t_data *img, t_comp *rock, char *file)
{
	rock->img = mlx_xpm_file_to_image(img->mlx, file, &rock->w, &rock->h);
	rock->addr = mlx_get_data_addr(rock->img, &rock->bpp, &rock->l_l,
			&rock->endian);
}

void	ft_fillcoll(t_data *img, t_comp *coll, char *file)
{
	coll->img = mlx_xpm_file_to_image(img->mlx, file, &coll->w, &coll->h);
	coll->addr = mlx_get_data_addr(coll->img, &coll->bpp, &coll->l_l,
			&coll->endian);
}

void	ft_filldoor(t_data *img, t_comp *door, char *file)
{
	door->img = mlx_xpm_file_to_image(img->mlx, file, &door->w, &door->h);
	door->addr = mlx_get_data_addr(door->img, &door->bpp, &door->l_l,
			&door->endian);
}
