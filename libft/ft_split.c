/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:00:34 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/04 16:13:29 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_count(const char *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i])
			count++;
		else
			if (s[i - 1] != c)
				count++;
	}
	return (count);
}

char	*ft_sub_split(char const *s, char c, unsigned int *j)
{
	char			*str;
	unsigned int	k;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	k = 0;
	while (s[*j] == c && s[*j])
		(*j)++;
	while (s[*j] != c && s[*j])
		str[k++] = s[(*j)++];
	str[k] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_count(s, c))
	{
		tab[i++] = ft_sub_split(s, c, &j);
	}	
	tab[i] = NULL;
	return (tab);
}
