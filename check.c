/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:34:00 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/06 21:52:36 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int		ft_checkPos(int direction, t_data *img)
{

/*1 is up, 2 is left, 3 is down, 4 is right*/
	if (direction == 1)
		if (checkUp(img) == 1)
			return 1;

	if (direction == 3)
		if (checkDown(img) == 1)
			return 1;

	if (direction == 2)
		if (checkLeft(img) == 1)
			return 1;

	if (direction == 4)
		if (checkRight(img) == 1)
			return 1;

return 0;

}


int		checkUp(t_data *img)
{
	int x;
	int y;

	x = img->PosX;
	y = img->PosY;
	if(img->points[y - 1][x] == '1')
		return 1;
	else
		return 0;
}

int		checkDown(t_data *img)
{
	int x;
	int y;

	x = img->PosX;
	y = img->PosY;
	if(img->points[y + 1][x] == '1')
		return 1;
	else
		return 0;
}

int		checkLeft(t_data *img)
{
	int x;
	int y;

	x = img->PosX;
	y = img->PosY;
	if(img->points[y][x - 1] == '1')
		return 1;
	else
		return 0;
}

int		checkRight(t_data *img)
{
	int x;
	int y;

	x = img->PosX;
	y = img->PosY;
	if(img->points[y][x + 1] == '1')
		return 1;
	else
		return 0;
}
