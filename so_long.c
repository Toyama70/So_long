/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:56:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/01/03 12:59:17 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef	struct s_hero {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
	int		w;
	int		h;
}			t_hero;

typedef struct s_data {
	void	*mlx;
	void	*win;
//	void	*her;

	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
	t_hero	her;
}			t_data;

/*
int		deal_key(int key, void *param)
{

	write(1, "x", 1);

	return (0);
}*/
void	ft_img(t_data *img, t_hero *hero, char *file)
{

	hero->img = mlx_xpm_file_to_image(img->mlx, file, &hero->w, &hero->h);

	hero->addr = mlx_get_data_addr(hero->img, &hero->bpp, &hero->l_l, &hero->endian);


}



void	ft_matrix(t_data *img)
{
	t_hero hero;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1280, 720, "So_long");
//	mlx_pixel_put(img->mlx, img->win, 5, 5, 0x00FF0000);

		
	//mlx_key_hook(img->win, deal_key, (void *)0); 

	ft_img(img, &hero, "hero.xpm");
	img->her = hero;	
	mlx_put_image_to_window(img->mlx, img->win, img->her.img, 50, 50)	;
	
	
	
	
	
	
	mlx_loop(img->mlx);

}


int	main(void)
{
	t_data img;

	ft_matrix(&img);
	mlx_loop(img.mlx);
	system("leaks a.out");
}
