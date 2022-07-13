/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:50:15 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/02 01:44:13 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	if (dstsize < ft_strlen(dst))
		res = ft_strlen(src) + dstsize;
	else
		res = ft_strlen(src) + ft_strlen(dst);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (i + 1 < dstsize && src[j])
	{	
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
