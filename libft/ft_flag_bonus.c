/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:06:49 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/31 09:26:21 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dash_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	size_t	nbr;
	size_t	count_inital;
	size_t	len_arg;

	str_nbr = ft_arg_multi(str, i);
	i += ft_strlen(str_nbr);
	str_arg = ft_sub_char(str[i], ptr);
	nbr = ft_atoi(str_nbr);
	count_inital = 0;
	if (str[i] == 'p')
		len_arg = ft_strlen(str_arg) + 2;
	else
		len_arg = ft_strlen(str_arg);
	*z += len_arg;
	ft_putstr(str_arg, str[i]);
	if (len_arg < nbr)
		count_inital = nbr - len_arg + 1;
	while (count_inital && --count_inital)
		*z += ft_put_char(' ');
	count_inital = ft_strlen(str_nbr);
	free(str_nbr);
	return (count_inital + 1);
}

int	ft_zero_sub_flag(const char *str, int i, char *c, int *z)
{
	int	ret;

	ret = 0;
	if (str[i] == 's' || str[i] == 'c')
		*c = ' ';
	if (str[i] == 'p')
		ret += 2;
	if (str[i] == 'p')
		*z += 2;
	return (ret);
}

int	ft_zero_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	char	c;
	size_t	nbr;
	size_t	count_inital;

	str_nbr = ft_arg_multi(str, i);
	i += ft_strlen(str_nbr);
	str_arg = ft_sub_char(str[i], ptr);
	nbr = ft_atoi(str_nbr);
	count_inital = ft_strlen(str_arg);
	*z += count_inital;
	c = '0';
	count_inital += ft_zero_sub_flag(str, i, &c, z);
	if (str_arg[0] && str_arg[0] == '-')
		ft_put_char('-');
	while (count_inital++ < nbr)
		*z += ft_put_char(c);
	if (str_arg[0] && str_arg[0] == '-')
		ft_putstr_minus_less(str_arg, str[i]);
	else
		ft_putstr(str_arg, str[i]);
	count_inital = ft_strlen(str_nbr);
	free(str_nbr);
	return (count_inital + 1);
}
