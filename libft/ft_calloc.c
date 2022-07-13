/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:49:47 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/01 16:13:31 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	i = 0;
	ret = malloc(count * size);
	if (ret == NULL)
	{
		free(ret);
		exit (1);
	}
	while (i < count * size)
		*((char *)ret + i++) = 0;
	return ((void *)ret);
}
