/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:11:55 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/16 23:29:02 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_check_args(int argc)
{
	if (argc > 2)
	{
		printf("Error: Too Much arguments\n");
		exit (0);
	}
	if (argc < 2)
	{
		printf("Error: Need 2 arguments\n");
		exit (0);
	}
}

int	ft_check_extension(char *str)
{
	char	**tab;

	tab = ft_split(str, '.');
	if (tab[1] == NULL)
	{
		printf("Error\nInvalid map name\n");
		return (1);
	}
	if (ft_strlen(tab[1]) != 3)
	{
		printf("Error\nInvalid extension: %s\n", tab[1]);
		return (1);
	}
	if (ft_strlen(tab[0]) == 5 && ft_strncmp(tab[0], "maps/", 5) == 0)
	{
		printf("Error\nInvalid name\n");
		return (1);
	}
	ft_free_tab(tab);
	return (0);
}

int	ft_checker(int argc, char **argv, t_data *data)
{
	char	*filename;

	ft_check_args(argc);
	filename = argv[1];
	printf("\n\n------------- %s ------------\n", filename);
	if (ft_check_extension(filename))
		return (1);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
	{
		printf("Error: Unable to open map %s\n", filename);
		return (1);
	}
	return (0);
}
