/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:01:33 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/03 11:05:27 by ybestrio         ###   ########.fr       */
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

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *theString);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_getrest(char *fbuff);
char	*get_next_line(int fd);




#endif
