/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:49:59 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/02 01:21:06 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s2 + i) != *((unsigned char *)s1 + i))
		{
			if (*((unsigned char *)s2 + i) - *((unsigned char *)s1 + i) != 0)
				return (*((unsigned char *)s1 + i)
					- *((unsigned char *)s2 + i));
			else
				return (0);
		}
		i++;
	}
	return (0);
}
