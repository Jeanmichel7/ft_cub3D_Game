/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:18:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/31 09:26:23 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse_0x(char	*str)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_strlen(str);
	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ret[i] = str[len - i - 1];
		i++;
	}
	ret[i] = '\0';
	free (str);
	return (ret);
}

char	*ft_put_ptr(unsigned long long int nbr, char *base)
{
	char			*str;
	char			*ret;
	int				i;

	if (!nbr)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (17));
	i = 0;
	while (nbr)
	{
		str[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	str[i] = '\0';
	while (--i >= 0)
		str[i] = base[(int)str[i]];
	ret = ft_strreverse_0x(str);
	return (ret);
}
