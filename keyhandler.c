/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:13:00 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/06 17:35:20 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int		deal_key(int key, t_data *img)
{

	(void)(img);

	if (key == 0)
		move_left(img);
	if (key == 13)
		move_up(img);
	if (key == 1)
		move_down(img);
	if (key == 2)
		move_right(img);
	if (key == 53)
		printf("ESC\n");

	return (0);
}

void	move_up(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);
	
	img->PosY--;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	
}
	
void	move_down(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);
	
	img->PosY++;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	
}

void	move_left(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);
	
	img->PosX--;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	
}

void	move_right(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);
	
	img->PosX++;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	
}
