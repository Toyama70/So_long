/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:13:00 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/10 13:36:17 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	deal_key(int key, t_data *img)
{
	if (key == 0)
		move_left(img);
	if (key == 13)
		move_up(img);
	if (key == 1)
		move_down(img);
	if (key == 2)
		move_right(img);
	if (key == 53)
		escape(img);
	return (0);
}

void	move_up(t_data *img)
{
	if (ft_checkpos(1, img) == 1)
		return ;
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img,
			img->posx * 64, img->posy * 64);
	if (img->points[img->posy][img->posx] == 'C')
		ft_collecting(img);
	img->posy--;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		ft_is_exit(img);
	ft_movecount(img);
}

void	move_down(t_data *img)
{
	if (ft_checkpos(3, img) == 1)
		return ;
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img,
			img->posx * 64, img->posy * 64);
	if (img->points[img->posy][img->posx] == 'C')
		ft_collecting(img);
	img->posy++;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		ft_is_exit(img);
	ft_movecount(img);
}

void	move_left(t_data *img)
{
	if (ft_checkpos(2, img) == 1)
		return ;
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img,
			img->posx * 64, img->posy * 64);
	if (img->points[img->posy][img->posx] == 'C')
		ft_collecting(img);
	img->posx--;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		ft_is_exit(img);
	ft_movecount(img);
}

void	move_right(t_data *img)
{
	if (ft_checkpos(4, img) == 1)
		return ;
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img,
			img->posx * 64, img->posy * 64);
	if (img->points[img->posy][img->posx] == 'C')
		ft_collecting(img);
	img->posx++;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->posx * 64,
		img->posy * 64);
	if (img->points[img->posy][img->posx] == 'E')
		ft_is_exit(img);
	ft_movecount(img);
}
