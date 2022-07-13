/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:18:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/31 09:26:21 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	ft_putuchar(char c, unsigned int *len)
{
	write(1, &c, 1);
	*len += 1;
}
*/

static unsigned int	ft_scale(long nb, int len)
{
	unsigned int	res;

	res = 1;
	while ((nb / len) > 0)
	{
		nb = nb / len;
		res *= len;
	}
	return (res);
}

char	*ft_putunbr_base(unsigned int nbr, char *base)
{
	int				len_base;
	long			scale;
	char			*str;
	unsigned int	i;

	i = 0;
	len_base = ft_strlen(base);
	scale = ft_scale(nbr, ft_strlen(base));
	str = malloc(sizeof(char) * (scale + 1));
	while (scale > 0)
	{
		str[i] = base[nbr / scale];
		nbr %= scale;
		scale /= len_base;
		i++;
	}
	str[i] = '\0';
	return (str);
}
