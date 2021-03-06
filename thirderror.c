/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirderror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:44:14 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/10 13:44:30 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_limitmapsize(t_data *img, t_mapsize *map)
{
	if (map->h > 20 || map->l > 39)
	{
		printf("Map size too big, wouldn't fit on screen, error");
		free_tab(img->points);
		exit(1);
	}
	if (map->h < 3 || map->l < 3)
	{
		printf("Map size too small, wouldn't allow walls + min item amount");
		free_tab(img->points);
		exit(1);
	}
}

void	ft_wallexit(t_data *img)
{
	free_tab(img->points);
	printf("border is not a wall error");
	exit(1);
}

void	ft_wallaround(t_data *img, t_mapsize *map)
{
	int	i;

	i = 0;
	while (i < map->l)
	{
		if (img->points[0][i] != '1')
			ft_wallexit(img);
		i++;
	}
	i = 0;
	while (i < map->l)
	{
		if (img->points[map->h - 1][i] != '1')
			ft_wallexit(img);
		i++;
	}
}

void	ft_wallaround2(t_data *img, t_mapsize *map)
{
	int	i;

	i = 0;
	while (i < map->h)
	{
		if (img->points[i][0] != '1')
			ft_wallexit(img);
		i++;
	}
	i = 0;
	while (i < map->h)
	{
		if (img->points[i][map->l - 1] != '1')
			ft_wallexit(img);
		i++;
	}
}

void	ft_checkmin(t_data *img, t_mapsize *map)
{
	int	i;
	int	k;

	i = -1;
	while (++i < map->h)
	{
		k = -1;
		while (++k < map->l)
		{
			if (img->points[i][k] == 'E')
				img->doorcount++;
			if (img->points[i][k] == 'C')
				img->collcount++;
		}
	}
	if (img->doorcount <= 0 || img->collcount <= 0)
	{
		free_tab(img->points);
		printf("Invalid input, door or collectible missing");
		exit(1);
	}
}
