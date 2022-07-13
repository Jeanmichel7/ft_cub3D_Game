/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_dot_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:53:11 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/31 09:26:21 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_neg(int *z)
{
	*z += ft_put_char('-');
	return (-1);
}

static void	ft_dot_flag_sub( size_t nbr, char *str_arg, int *z)
{
	size_t	i;

	i = 0;
	while (i < nbr)
		ft_put_char(str_arg[i++]);
	*z -= ft_strlen(str_arg) - i;
}

static void	ft_dit_sub_flag(char *str_arg, char c)
{
	if (str_arg && str_arg[0] == '-')
		ft_putstr_minus_less(str_arg, c);
	else
		ft_putstr(str_arg, c);
}

int	retour_fct(char *str_nbr, size_t count_inital)
{
	free(str_nbr);
	return (count_inital + 1);
}

int	ft_dot_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	size_t	count_inital;

	str_nbr = ft_arg_multi(str, i);
	if (str_nbr[0] != 0)
	{
		i += ft_strlen(str_nbr);
		str_arg = ft_sub_char(str[i], ptr);
		count_inital = ft_strlen(str_arg);
		if (str_arg && str_arg[0] == '-')
			count_inital += ft_is_neg(z);
		*z += count_inital;
		if (str[i] != 's' && str[i] != 'c')
			while (count_inital++ < (size_t)ft_atoi(str_nbr))
				*z += ft_put_char('0');
		if (ft_strlen(str_arg) > (size_t)ft_atoi(str_nbr) && str[i] == 's')
			ft_dot_flag_sub(ft_atoi(str_nbr), str_arg, z);
		else
			ft_dit_sub_flag(str_arg, str[i]);
		count_inital = ft_strlen(str_nbr);
	}
	else
		count_inital = 0;
	return (retour_fct(str_nbr, count_inital));
}
