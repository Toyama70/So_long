/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:34:00 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/10 13:33:22 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_checkpos(int direction, t_data *img)
{
	if (direction == 1)
		if (checkup(img) == 1)
			return (1);
	if (direction == 3)
		if (checkdown(img) == 1)
			return (1);
	if (direction == 2)
		if (checkleft(img) == 1)
			return (1);
	if (direction == 4)
		if (checkright(img) == 1)
			return (1);
	return (0);
}

int	checkup(t_data *img)
{
	int	x;
	int	y;

	x = img->posx;
	y = img->posy;
	if (img->points[y - 1][x] == '1')
		return (1);
	else
		return (0);
}

int	checkdown(t_data *img)
{
	int	x;
	int	y;

	x = img->posx;
	y = img->posy;
	if (img->points[y + 1][x] == '1')
		return (1);
	else
		return (0);
}

int	checkleft(t_data *img)
{
	int	x;
	int	y;

	x = img->posx;
	y = img->posy;
	if (img->points[y][x - 1] == '1')
		return (1);
	else
		return (0);
}

int	checkright(t_data *img)
{
	int	x;
	int	y;

	x = img->posx;
	y = img->posy;
	if (img->points[y][x + 1] == '1')
		return (1);
	else
		return (0);
}
