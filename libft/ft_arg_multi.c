/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:09:16 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/11 18:56:01 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arg_multi(const char *str, int i)
{
	int		j;
	char	*nbr;

	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		j++;
	}
	nbr = malloc(sizeof(char) * (j + 1));
	i -= j;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr[j++] = str[i++];
	nbr[j] = '\0';
	return (nbr);
}
