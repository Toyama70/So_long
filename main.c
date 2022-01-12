/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:04:15 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/10 13:48:22 by ybestrio         ###   ########.fr       */
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

int	mouse_hook(t_data *img)
{
	free_tab(img->points);
	exit(0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (n > i && (ptr_s1[i] || ptr_s2[i]))
	{
		if (ptr_s1[i] != ptr_s2[i])
		{
			if (ptr_s1[i] > ptr_s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char		*line;
	char		**tab;
	t_mapsize	map;
	t_data		img;
	t_axis		axis;

	line = NULL;
	ft_errorhandler1(argc, argv);
	img.movecount = 0;
	tab = ft_parsemap(line, &img, argv[1], &axis);
	map = ft_setmap(tab);
	img.points = tab;
	ft_errorhandler2(&img, &map);
	ft_matrix(&img, map, tab);
	mlx_key_hook(img.win, deal_key, &img);
	mlx_hook(img.win, 17, 1L << 2, mouse_hook, &img);
	mlx_loop(img.mlx);
	free_tab(tab);
}
