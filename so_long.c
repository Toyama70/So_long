/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:56:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/02 12:26:38 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
}			t_data;

void	ft_matrix
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_mew_window(mlx, 1280, 720, "So_long");
	

}

/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}*/


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720 , "Hello world!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_l,
								&img.endian);
	my_mlx_pixel_put(&img, 10, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
