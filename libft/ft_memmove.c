/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:50:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/02 01:37:01 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp;

	temp = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src > dst)
	{
		while (i < len)
		{
			*((char *)dst + i) = temp[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			*((char *)dst + len - 1) = temp[len - 1];
			len--;
		}
	}
	return (dst);
}
