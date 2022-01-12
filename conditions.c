/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:00:36 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/10 13:37:18 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_collecting(t_data *img)
{
	img->points[img->posy][img->posx] = '0';
	img->remain--;
}

void	ft_movecount(t_data *img)
{
	img->movecount += 1;
	printf("Your movecount is : %d\n", img->movecount);
}

void	escape(t_data *img)
{
	free_tab(img->points);
	exit(0);
}

void	ft_is_exit(t_data *img)
{
	if (img->remain != 0)
		mlx_string_put(img->mlx, img->win, 5, 0, 0x00FFFFFF,
			"You didn't collect all of the collectibles yet !");
	else
	{
		free_tab(img->points);
		exit(0);
	}
	return ;
}
