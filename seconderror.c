/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seconderror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:45:53 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/10 13:43:58 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_errorhandler2(t_data *img, t_mapsize *map)
{
	img->collcount = 0;
	img->doorcount = 0;
	ft_playernumber(img, map);
	ft_forbiddenchar(img, map);
	ft_limitmapsize(img, map);
	ft_checkmin(img, map);
	ft_wallaround(img, map);
	ft_wallaround2(img, map);
}

void	ft_checkprechar(char c)
{
	if (c == 'C' || c == '0' || c == '1' || c == 'E' || c == 'P' || c == '\n')
		return ;
	else
	{
		printf("Forbidden key in file or wrong line length");
		exit(1);
	}
}

void	ft_checkchar(char c, t_data *img)
{
	if (c == 'C' || c == '0' || c == '1' || c == 'E' || c == 'P' || c == '\n')
		return ;
	else
	{
		free_tab(img->points);
		printf("Forbidden key in file or wrong line length");
		exit(1);
	}
}

void	ft_forbiddenchar(t_data *img, t_mapsize *map)
{
	int	i;
	int	k;

	i = 0;
	while (i < map->h)
	{
		k = 0;
		while (k < map->l)
		{
			ft_checkchar(img->points[i][k], img);
			k++;
		}
		i++;
	}
}

void	ft_playernumber(t_data *img, t_mapsize *map)
{
	int	pcount;
	int	i;
	int	k;

	i = -1;
	pcount = 0;
	while (++i < map->h)
	{
		k = -1;
		while (++k < map->l)
		{
			if (img->points[i][k] == 'P')
				pcount++;
		}
	}
	if (pcount != 1)
	{
		free_tab(img->points);
		printf("Invalid input");
		exit(1);
	}
}
