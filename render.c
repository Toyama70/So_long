/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:40:55 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/06 14:55:48 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_renderer(t_data *img, t_mapsize M, char **tab)
{

	render_back(img, M);
	render_rock(img, M, tab);
	render_hero(img, M, tab);
	render_coll(img, M, tab);
	render_door(img, M, tab);
}


void	render_door(t_data *img, t_mapsize M, char **tab)
{
	int	i;
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == 'E')
				mlx_put_image_to_window(img->mlx, img->win, img->door.img, 64 * k, 64 * i);
			k++;
		}
		i++;
	}
}

void	render_coll(t_data *img, t_mapsize M, char **tab)
{
	int	i;
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == 'C')
				mlx_put_image_to_window(img->mlx, img->win, img->coll.img, 64 * k, 64 * i);
			k++;
		}
		i++;
	}
}

void	render_hero(t_data *img, t_mapsize M, char **tab)
{

	int	i;
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == 'P')
				mlx_put_image_to_window(img->mlx, img->win, img->her.img, 64 * k, 64 * i);
			k++;
		}
		i++;
	}
}

void	render_rock(t_data *img, t_mapsize M, char **tab)
{

	int	i;
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			if(tab[i][k] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->rock.img, k * 64, i *64);
			k++;
		}
		i++;
	}
}


void	render_back(t_data *img, t_mapsize M)
{
	int	i;
	int k;

	i = 0;
	while (i < M.H)
	{
		k = 0;
		while (k < M.L)
		{
			mlx_put_image_to_window(img->mlx, img->win, img->txtr.img, k * 64, i *64);
			k++;
		}
		i++;
	}
}
