/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:10:42 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/03 14:20:11 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(dst);
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	dstsize = dstsize - i - 1;
	while (dstsize > 0 && *src)
	{
		dst[i] = *src;
		src++;
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	if (dstsize == 0)
		return (ft_strlen(dst) + ft_strlen(src));
	return (i);
}
