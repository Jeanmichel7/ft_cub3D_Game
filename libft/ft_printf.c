/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:16:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/31 09:34:09 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_sub_flag(const char *str, int i, va_list ptr, int *z)
{
	int	ret;

	if (str[i] == '-' && str[i + 1] != '.')
		ret = ft_dash_flag(str, ++i, ptr, z);
	else if (str[i] == '-' && str[i + 1] == '.')
		ret = ft_dot_flag(str, i + 2, ptr, z) + 1;
	else if (str[i] == '.' && str[i - 1] != '-')
		ret = ft_dot_flag(str, ++i, ptr, z);
	else if (str[i] == '0' && str[i + 1] != '-')
		ret = ft_zero_flag(str, ++i, ptr, z);
	if (str[i] == ' ')
		ret = ft_space_flag(str, ++i, ptr, z);
	if (str[i] == '#')
		ret = ft_diese_flag(str, ++i, ptr, z);
	if (str[i] == '+')
		ret = ft_plus_flag(str, ++i, ptr, z);
	return (ret);
}

char	*ft_sub_char(char c, va_list ptr)
{
	char	*tmp;

	tmp = NULL;
	if (c == 'd' || c == 'i')
		tmp = ft_itoa(va_arg(ptr, int));
	else if (c == 'o')
		tmp = ft_putunbr_base(va_arg(ptr, unsigned int), "01234567");
	else if (c == 'u')
		tmp = ft_uitoa(va_arg(ptr, unsigned int));
	else if (c == 'x')
		tmp = ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		tmp = ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (c == 's')
		return (va_arg(ptr, char *));
	else if (c == 'c')
		tmp = ctos(va_arg(ptr, int));
	else if (c == 'p')
	{
		ft_putstr("0x", c);
		tmp = ft_put_ptr(va_arg(ptr, unsigned long long int), PTR);
	}
	else if (c == '%')
		return ("%");
	return (tmp);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		z;

	i = -1;
	z = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == '-' || str[i] == '0' || str[i] == '.' || str[i] == ' '
				|| str[i] == '#' || str[i] == '+')
				i += ft_sub_flag(str, i, ptr, &z);
			else if (str[i] == 'p')
				z += ft_putstr(ft_sub_char(str[i], ptr), str[i]) + 2;
			else
				z += ft_putstr(ft_sub_char(str[i], ptr), str[i]);
		}
		else
			z += ft_put_char(str[i]);
	}
	va_end(ptr);
	return (z);
}
