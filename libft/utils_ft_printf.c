/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:58:35 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/05 19:58:41 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ctos(char c)
{
	char	*str;

	if (c == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

unsigned int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

unsigned int	ft_putstr(char *str, char c)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	if (str[0] == '\0' && c == 'c')
	{
		write (1, str, 1);
		free (str);
		return (1);
	}
	if (c == 's')
		return (write(1, str, len));
	else
	{
		write(1, str, len);
		if (str[0] == '%' || (str[0] == '0' && str[1] == 'x' && str[2] == '\0')
			|| (str[0] == '0' && str[1] == 'X' && str[2] == '\0'))
			return (len);
		else
			free (str);
		return (len);
	}
	return (0);
}

unsigned int	ft_write_minus_less(char *str)
{
	unsigned int	i;

	i = 1;
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
	return (i);
}

unsigned int	ft_putstr_minus_less(char *str, char c)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	if (c == 's')
		return (ft_write_minus_less(str));
	else
	{
		len = ft_write_minus_less(str);
		if (str[0] == '%' || (str[0] == '0' && str[1] == 'x' && str[2] == '\0')
			|| (str[0] == '0' && str[1] == 'X' && str[2] == '\0'))
			return (len);
		else
			free (str);
		return (len);
	}
	return (0);
}
