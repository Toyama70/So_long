/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:13:00 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/08 11:41:25 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int		deal_key(int key, t_data *img)
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
	if(ft_checkPos(1, img) == 1)
		return ;

	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);

	if (img->points[img->PosY][img->PosX] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img, img->PosX * 64, img->PosY * 64);

	if (img->points[img->PosY][img->PosX] == 'C')
		ft_collecting(img);

	img->PosY--;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	if (img->points[img->PosY][img->PosX] == 'E')
		ft_is_exit(img);

	ft_movecount(img);


}
	
void	move_down(t_data *img)
{
	
	if(ft_checkPos(3, img) == 1)
		return ;

	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);
	if (img->points[img->PosY][img->PosX] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img, img->PosX * 64, img->PosY * 64);

	if (img->points[img->PosY][img->PosX] == 'C')
		ft_collecting(img);
	
	img->PosY++;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	if (img->points[img->PosY][img->PosX] == 'E')
		ft_is_exit(img);
	
	ft_movecount(img);
}

void	move_left(t_data *img)
{
	
	if(ft_checkPos(2, img) == 1)
		return ;

	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);
	if (img->points[img->PosY][img->PosX] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img, img->PosX * 64, img->PosY * 64);
	if (img->points[img->PosY][img->PosX] == 'C')
		ft_collecting(img);
	
	img->PosX--;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	if (img->points[img->PosY][img->PosX] == 'E')
		ft_is_exit(img);
	
	ft_movecount(img);
}

void	move_right(t_data *img)
{
	
	if(ft_checkPos(4, img) == 1)
		return ;

	mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, img->PosX * 64, img->PosY * 64);
	if (img->points[img->PosY][img->PosX] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->door.img, img->PosX * 64, img->PosY * 64);
	if (img->points[img->PosY][img->PosX] == 'C')
		ft_collecting(img);
	
	img->PosX++;
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, img->PosX * 64, img->PosY * 64);

	if (img->points[img->PosY][img->PosX] == 'E')
		ft_is_exit(img);
	
	ft_movecount(img);
}
