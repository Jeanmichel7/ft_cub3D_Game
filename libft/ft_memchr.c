/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:49:56 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/02 01:19:02 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int n, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*((unsigned char *)s + i) == (unsigned char)n)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}
