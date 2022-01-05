/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:01:33 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/05 15:29:16 by ybestrio         ###   ########.fr       */
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
//	void	*her;
	
	t_txtr	txtr;
	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
	t_hero	her;
}			t_data;

typedef struct s_mapsize {
	int	length;
	int	height;
}	t_mapsize;

void free_tab(char **tab);
int	ft_readmap(t_mapsize *mapsize);
char **ft_parsemap(char *line);
void	ft_printmap(char **tab);
void	ft_img(t_data *img, t_hero *hero, char *file);
void	ft_matrix(t_data *img);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *theString);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_getrest(char *fbuff);
char	*get_next_line(int fd);




#endif
