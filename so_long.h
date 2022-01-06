/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:01:33 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/06 16:37:23 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <mlx.h>

typedef	struct s_hero {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
	int		w;
	int		h;
}			t_hero;

typedef struct	s_rock {

	void	*img;
	char	*addr;
	
	int		w;
	int		h;
	int		bpp;
	int		l_l;
	int		endian;

}			t_rock;

typedef struct	s_door {

	void	*img;
	char	*addr;
	
	int		w;
	int		h;
	int		bpp;
	int		l_l;
	int		endian;

}			t_door;

typedef struct	s_coll {

	void	*img;
	char	*addr;
	
	int		w;
	int		h;
	int		bpp;
	int		l_l;
	int		endian;

}			t_coll;

typedef struct	s_ground {

	void	*img;
	char	*addr;
	
	int		w;
	int		h;
	int		bpp;
	int		l_l;
	int		endian;

}			t_txtr;

typedef struct s_data {
	void	*mlx;
	void	*win;
	
	t_hero	her;
	t_txtr	txtr;
	t_rock	rock;
	t_door	door;
	t_coll	coll;
	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
	int		PosX;
	int		PosY;
}			t_data;


typedef struct s_mapsize {
	int	L;
	int	H;
}	t_mapsize;

int	ft_readmap(t_mapsize *mapsize);
char **ft_parsemap(char *line);
void	ft_printmap(char **tab);
void	ft_img(t_data *img, t_hero *hero, char *file);
void	ft_matrix(t_data *img, t_mapsize map, char **tab);
void	*ft_calloc(size_t elementCount, size_t elementSize);

/* Movement and key handling */

int     deal_key(int key, t_data *img);
void    move_up(t_data *img);
void    move_left(t_data *img);
void    move_right(t_data *img);
void    move_down(t_data *img);


/* Parsing map functions */

t_mapsize	ft_setmap(char **tab);
char **ft_parsemap(char *line); //will need argc argv
int	ft_readmap(t_mapsize *mapsize);



/* Read images and fill the data structure with rendering infos */

void	ft_fillhero(t_data *img, t_hero *hero, char *file);
void	ft_fillback(t_data *img, t_txtr *txtr, char *file);
void	ft_fillcoll(t_data *img, t_coll *coll, char *file);
void	ft_fillrock(t_data *img, t_rock *rock, char *file);
void	ft_filldoor(t_data *img, t_door *door, char *file);
void	ft_storeimages2(t_data *img, t_coll coll, t_door door);
void	ft_storeimages(t_data *img, t_hero hero, t_txtr txtr, t_rock rock);


/* Rendering functions */

void	render_back(t_data *img, t_mapsize M);
void	render_rock(t_data *img, t_mapsize M, char **tab);
void	render_hero(t_data *img, t_mapsize M, char **tab);
void	render_coll(t_data *img, t_mapsize M, char **tab);
void	render_door(t_data *img, t_mapsize M, char **tab);
void	render_back(t_data *img, t_mapsize M);
void	ft_renderer(t_data *img, t_mapsize M, char **tab);


/*Functions utils */

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *theString);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_getrest(char *fbuff);
char	*get_next_line(int fd);
void	free_tab(char **tab);



#endif
