/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:59:59 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/04 18:19:00 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (start >= ft_strlen(s) + 1)
		return (str);
	i = start;
	while (len && s[i])
	{
		str[i - start] = s[i];
		len--;
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
