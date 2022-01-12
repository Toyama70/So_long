/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:01:33 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/10 13:48:38 by ybestrio         ###   ########.fr       */
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

typedef struct s_axis {
	int		i;
	int		k;
}			t_axis;

typedef struct s_comp {
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		l_l;
	int		endian;

}			t_comp;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_comp	her;
	t_comp	txtr;
	t_comp	rock;
	t_comp	door;
	t_comp	coll;
	char	**points;
	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
	int		posx;
	int		posy;
	int		movecount;
	int		remain;
	int		doorcount;
	int		collcount;
}			t_data;

typedef struct s_mapsize {
	int	l;
	int	h;
}	t_mapsize;

void		ft_errorhandler2(t_data *img, t_mapsize *map);
char		**ft_parsemap(char *line, t_data *img, char *str, t_axis *axis);
void		ft_printmap(char **tab);
void		ft_img(t_data *img, t_comp *hero, char *file);
void		ft_matrix(t_data *img, t_mapsize map, char **tab);
void		*ft_calloc(size_t elementCount, size_t elementSize);
void		ft_isber(char *str);
void		ft_errorhandler1(int argc, char **argv);
void		ft_emptyarg(char *str);
void		ft_playernumber(t_data *img, t_mapsize *map);
void		ft_checkprechar(char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* Errors and Exceptions */
void		ft_forbiddenchar(t_data *img, t_mapsize *map);
void		ft_checkchar(char c, t_data *img);
void		ft_checkmin(t_data *img, t_mapsize *map);
void		ft_limitmapsize(t_data *img, t_mapsize *map);
void		ft_wallaround(t_data *img, t_mapsize *map);
void		ft_wallaround2(t_data *img, t_mapsize *map);
void		ft_wallexit(t_data *img);
void		ft_contentinvalid(char *str);

/* Checking winning or exit conditions */

void		ft_is_exit(t_data *img);
void		ft_collecting(t_data *img);
void		escape(t_data *img);
/* Movement and key handling */

int			deal_key(int key, t_data *img);
void		move_up(t_data *img);
void		move_left(t_data *img);
void		move_right(t_data *img);
void		move_down(t_data *img);
void		ft_movecount(t_data *img);

/* Check possible moves */

int			checkup(t_data *img);
int			ft_checkpos(int direction, t_data *img);
int			checkdown(t_data *img);
int			checkleft(t_data *img);
int			checkright(t_data *img);

/* Parsing map functions */

t_mapsize	ft_setmap(char **tab);
int			ft_readmap(t_mapsize *mapsize, char *str);

/* Read images and fill the data structure with rendering infos */

void		ft_fillhero(t_data *img, t_comp *hero, char *file);
void		ft_fillback(t_data *img, t_comp *txtr, char *file);
void		ft_fillcoll(t_data *img, t_comp *coll, char *file);
void		ft_fillrock(t_data *img, t_comp *rock, char *file);
void		ft_filldoor(t_data *img, t_comp *door, char *file);
void		ft_storeimages2(t_data *img, t_comp coll, t_comp door);
void		ft_storeimages(t_data *img, t_comp hero, t_comp txtr, t_comp rock);

/* Rendering functions */

void		render_back(t_data *img, t_mapsize M);
void		render_rock(t_data *img, t_mapsize M, char **tab);
void		render_hero(t_data *img, t_mapsize M, char **tab);
void		render_coll(t_data *img, t_mapsize M, char **tab);
void		render_door(t_data *img, t_mapsize M, char **tab);
void		render_back(t_data *img, t_mapsize M);
void		ft_renderer(t_data *img, t_mapsize M, char **tab);

/*Functions utils */

char		*ft_strjoin(char const *s1, char const *s2);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *theString);
char		*ft_strchr(const char *string, int searchedChar);
char		*ft_getrest(char *fbuff);
char		*get_next_line(int fd);
void		free_tab(char **tab);

#endif
